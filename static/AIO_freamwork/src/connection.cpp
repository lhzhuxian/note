#include "connection.hpp"




Message::Message() {
  memset(static_cast<aiocb *>(this), 0, sizeof(aiocb));
}
Message::Message(int fd, int kq, int method, void * buf, Connection * connec) {
  memset(static_cast<aiocb *>(this), 0, sizeof(aiocb));
  aio_sigevent.sigev_notify = SIGEV_KEVENT;
  aio_sigevent.sigev_notify_kqueue = kq;
  aio_sigevent.sigev_notify_kevent_flags = EV_ONESHOT;
  aio_reqprio = 0;
  aio_buf = buf;
 
  aio_nbytes = strlen(buf);
  aio_offset = 0;
  aio_fildes = fd;
  if (method) {
    aio_lio_opcode = LIO_WRITE;
  } else {
    aio_lio_opcode = LIO_READ;
  }
  aio_sigevent.sigev_value.sival_ptr = this;
  method_ = method;
}


ReadMessage::ReadMessage(int fd, int kq, int method, void * buf, int id, Connection * connec):Message(fd, kq, method, buf, connec), id_(id) {
}

ReadMessage::~ReadMessage() {
  free(const_cast<void*> (aio_buf));
}

int ReadMessage::ReceiveBlock() {
  // check whether there is an error or empty buf
  // if yes, ready to close the conneciton
  // if solved is euqal to BUFFNUM, return -1, else return 0
  // return 1 if received request
  
  if (aio_return(this) == -1){
    perror("Read error:");
    int tmp = connec_->solved_.fetch_add(1, memory_order_relaxed);
    if (tmp == BUFFNUM - 1) {
      return -1;
    } else {
      return 0;
    }
  }
  
  // check the byte number read
  void * tmp = const_cast<void *> (aio_buf);  
  char * tmp_char = static_cast<char *>(tmp);
  cout << tmp_char << endl;
  if (strlen(tmp_char) == 0){
    int tmp = connec_->solved_.fetch_add(1, memory_order_relaxed);
    if (tmp == BUFFNUM - 1) {
      return -1;
    } else {
      return 0;
    }
  } else {
    //cout << "Block " << id_ << "received" << endl;
  }
  connec_->ring_.set_buf_(id_, tmp, connec_->req_list_, connec_->get_status());
  connec_->ring_.received_[id_] = 1;
  return 1;
}


Connection::Connection(int fd, int kq):fd_(fd), kq_(kq), status_(1), shut_sig_(0), solved_(0), req_list_(new RequestList(fd, kq)),  next_(NULL), prev_(NULL) {
  
}

Connection::~Connection(){
  delete req_list_;
  close(fd_);
}

void Connection::ReturnWriteBlock() {
  if(req_list_->ReturnWrite()) {
    ring_.status_.store(1);
    for(int i = 0; i <  BUFFNUM; i++) {
      aio_read(message_[i]);
    }
    req_list_.StartSend();
  }
}


int on_message_begin(http_parser* parser) {

  parser->data = new Request();
  return 0;
}

/*
int on_headers_complete(http_parser* parser) {

  return 0;
}
*/

int on_message_complete(http_parser* parser) {
  // add the complete request to RequestList
  Request * request = static_cast<Request *> (parser->data);
  RequestList * tmp_list = static_cast<RequestList*> (parser->list);
  tmp_list->AddRequest(request);
  parser->data = NULL;
  
  return 0;
}
int on_body(http_parser* parser, const char* buf, size_t len){
  Request * request = static_cast<Request *> (parser->data);
  request->set_data(buf, len);
  return 0;
}

int on_url(http_parser* parser, const char* buf, size_t len) {
  Request * request = static_cast<Request *> (parser->data);
  request->set_url(buf, len);
  request->set_method(http_method_str(http_method(parser->method)));
  return 0;
}

int on_header_field(http_parser* parser, const char* buf, size_t len) {
  Request * request = static_cast<Request *> (parser->data);
  request->set_headers(buf, len);
  return 0;
}

int on_header_value(http_parser* parser, const char* buf, size_t len) {
  Request * request = static_cast<Request *> (parser->data);
  request->set_values(buf, len);
  return 0;
}


RingBuffer::RingBuffer() {
  for (int i = 0; i < BUFFNUM; ++i) {
    buf_[i] = malloc(BUFFSIZE + 1);
  }
  http_parser_init(&parser_, HTTP_REQUEST);
  stone_ = 0;
  setting_null_.on_message_begin = on_message_begin;
  setting_null_.on_header_field = on_header_field;
  setting_null_.on_header_value = on_header_value;
  setting_null_.on_url = on_url;
  setting_null_.on_status = 0;
  setting_null_.on_body = on_body;
  //setting_null_.on_headers_complete = on_headers_complete;
  setting_null_.on_message_complete = on_message_complete;

}





void RingBuffer::set_buf_(int id, void * buf, RequestList * list) {
  // put down the read buf
  // check if the stone is in this block which means it is your turn to parse
 
  mutex_[id].lock();
  buf_[id] = buf;
  mutex_[id].unlock();
  if (stone_ == id) {
    ParseBuffer(id, list);
  }
  list->HandleRequest();
  status.store(list->get_status());
}



int RingBuffer::CheckReadRing(int id) {
  // check if the next buf is ready
  // if not drop the stone
  lock_guard<mutex> g(mutex_[id]);
  if (buf_[id]) {
    return 1;
  } else {
    stone_ = id;
    return 0;
  }
}


void RingBuffer::set_message_(aiocb * message, int id) {
  message_[id] = message;
}


void RingBuffer::ParseBuffer(int id, RequestList * list) {
  parser_.list = list;
  while (CheckReadRing(id)) {
    const char * tmp = static_cast<char *> (buf_[id]);
   
    http_parser_execute(&parser_, &setting_null_, tmp, strlen(tmp));
    memset(buf_[id], 0, BUFFSIZE + 1);
    buf_[id] = NULL;
    if(status_.load()) {
      aio_read(message_[id]);
      received_[id] = 0;
    }
    id = Next(id);
  }
  
}


int RingBuffer::Next(int id) {
  if (++id >= BUFFNUM) {
    id = 0;
  }
  return id;
}
void * RingBuffer::get_buf_(int id) {
  void * tmp = buf_[id];
  buf_[id] = NULL;
  return tmp;
}
