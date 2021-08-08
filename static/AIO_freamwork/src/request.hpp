#ifndef _REQUEST_H
#define _REQUEST_H


#include "common.hpp"


struct Request {
  int id_;
  string method_;
  string url_;
  vector<string> headers_;
  vector<string> values_;
  string data_;
   
  void set_method(const char * data);
  void set_url(const char * data, unsigned int length);
  void set_headers(const char * data, unsigned int length);
  void set_values(const char * data, unsigned int length);
  void set_data(const char * data, unsigned int length);
};


class RequestList {
  class Node {
  public:
    int id_;
    Request * req_;
    void * res_;
    Node * next_;
  };
  Node * head_;
  Node * tail_;




  atomic<int> tolerance_; // atomic
  atmoic<int> status_;  

  Node * current_res_;
  atomic<Node *> current_req_; // atomic
  mutex loc_;
  int fd_;
  int kq_;
  int id_; // atomic
  
public:
  RequestList(int fd, int kq);
  ~RequestList();
  int get_status();
  int ReturnResponse();
  void HandleRequest();
  void AddRequest(Request * req);
  int SendResponse(char * buf);
  void StartSend();
  
  int ReturnWrite();
};

string ReadFileIntoString(char * filename);
void SendResponse(int fd, int kq, char * buf);
char * handler(Request * req);
#endif
