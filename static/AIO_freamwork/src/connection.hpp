#ifndef _CONNECTION_H_
#define _CONNECTION_H_


#include "common.hpp"
#include "request.hpp"

class RingBuffer {
  void * buf_[BUFFNUM];
  aiocb * message_[BUFFNUM];
  
  int received_[BUFFNUM];
  atomic<int> status_;

  mutex mutex_[BUFFNUM];
  int stone_;
  http_parser parser_;
  http_parser_settings setting_null_;
public:
  RingBuffer();

  void set_buf_(int id, void * buf, RequestList *list);
  void * get_buf_(int id);
  
  void set_write_ring_(int id, void * buf);
  void set_message_(aiocb * message, int id);
  int Next(int id);
  int CheckReadRing(int id);
  void ParseBuffer(int id, RequestList * list);
  


  void CpyBuf(void * data, int len, int id);
  void SetNull(int i);
  void LockBuffer(int i);
  void UnlockBuffer(int i);


  void * operator[](int i);
};


struct Connection {
  int fd_;
  int kq_;
  int shut_sig_;

  atomic<int> solved_;
  RingBuffer ring_;
  
  RequestList * req_list_;
  
  Connection * next_;
  Connection * prev_;
  
  Connection(int fd, int kq);
  ~Connection();
  void ReturnWriteBlock();
};





struct Message : aiocb {
  bool method_; // 0 read 1 write
  Connection * connec_;
  Message();
  Message(int fd, int kq, int method, char * buf);
};

struct ReadMessage : Message {
  int id_;
  ReadMessage(int fd, int kq, int mehtod, void * buf, int id, Connection * connec);
  ~ReadMessage();
  int ReceiveBlock();
};

int on_message_begin(http_parser* parser);
int on_headers_complete(http_parser* parser);
int on_message_complete(http_parser* parser) ;
int on_body(http_parser* parser, const char* buf, size_t len);
int on_url(http_parser* parser, const char* buf, size_t len);
int on_header_field(http_parser* parser, const char* buf, size_t len);


#endif