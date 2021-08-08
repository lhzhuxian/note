
#include "request.hpp"
#include "connection.hpp"



void Request::set_method(const char *data) {
  method_ = data;
}

void Request::set_url(const char * data, unsigned int len){
  url_ = url_ + string(data, len);
}

void Request::set_headers(const char * data, unsigned int len){
  // check if the latest head is complete
  size_t size = headers_.size();
  if(size > values_.size()) {
    headers_[size - 1] = headers_[size - 1] + string(data, len);
  } else { 
    headers_.push_back(string(data, len));
  }
}
void Request::set_values(const char * data, unsigned int len){
  // check if the latest value is complete
  size_t size = values_.size();
  if (size < headers_.size()) {
    values_.push_back(string(data, len));
  } else {
    values_[size - 1] = values_[size - 1] + string(data, len);
  }
}

void Request::set_data(const char *data, unsigned int len) {
  data_ = data_ + string(data, len);
}








RequestList::RequestList(int fd, int kq): head_(NULL), tail_(NULL), current_res_(NULL), current_req(NULL), fd_(fd), kq_(kq), id_(0) {}

RequestList::~RequestList() {
  while(head_) {
    Node * temp = head_;
    head_ = head_->next_;
    delete temp->req_;
    delete temp;
  }
}

int RequestList::get_status() {
  return status_.load();
}

int RequestList::ReturnResponse() {
  tolerance_.fetch_sub(1, memory_order_relaxed);
  return 
}

void RequestList::AddRequest(Request * req) {
  Node *tmp = new Node();
  tmp->id_ = ++id_;
  tmp->req_ = req;
  tmp->next_ = NULL;
  if (head_ == NULL) {
    head_ = tmp;
    tail_ = tmp;
    
  } else {
    tail_->next_ = tmp;
    tail_ = tmp;
    // race
    if(current_req_.load() == NULL) current_req_.store(tail_);
    //
  }
}

void RequestList::HandleRequest() {
  
  Node * tmp = current_req_.load();
  if(tmp == NULL) return;
  // CAS
  // if current_res_ wasn't changed by the other thread, pick one out
  while(current_req_.comapre_exchange_weak(tmp, tmp->next )) {
    handler(tmp, this);
  }
    
}


int RequestList::SendResponse(void * buf, Node * req) {
  req->res_ = buf;
  if(!get_status())  return 0;
  return StartSend();
}
int RequestList:: StartSend() {
  while(current_res_->res_) {
    if(tolerance_.load() > g_connec_tolerance) {
      status_.store(0);
      return 0;
    }
    Message * res = new Message(fd_, kq_, 1, current_res_->res_);
    aio_write(res);
    tolerance_.fetch_add(1, memory_order_relaxed);
    current_res_ = current_res_->next_;
  }
  return 1;
}

int RequestList::ReturnWrite () {
  // 1 need to restart the connection 0 nothing need to be done
  tolerance_.fetch_sub(1, memory_order_relaxed);
  if(!status.load()) {
    if(tolerance.load() < (g_connec_tolerance / 2)) { 
      status.store(1);
      return  1;
    } 
  }
  return 0;
}



string ReadFileIntoString(char * filename) {
  ifstream ifile(filename);
  ostringstream buf;
  char ch;
  while(buf&&ifile.get(ch)) {
    buf.put(ch);
  }
  return buf.str();
}

void handler(Node * req, RequestList * req_list) {
  // replace this handler with server logic

  
  string data = ReadFileIntoString("response2.txt");
  
  char * buf = static_cast<char*> (malloc(data.size() + 1));

  memcpy(buf, data.c_str(), data.size() + 1);

  int tmp = req_list->SendResponse(buf, req);
}
