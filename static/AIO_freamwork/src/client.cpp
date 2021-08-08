#include "common.hpp"
#include <fstream>
#include <sstream>

string readfile (char * filename) {
  ifstream ifile(filename);
  ostringstream buf;
  char ch;
  while(buf&&ifile.get(ch)) buf.put(ch);
  return buf.str();
}
void send_request(string msg) {
  // set up listener
  int status;
  addrinfo hints;
  addrinfo *servinfo;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(NULL, "8080", &hints, &servinfo)) != 0) {
    cerr << "getaddrinfo error : " << gai_strerror(status) << endl;
  }

  int sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
  cout << sockfd << endl;
  connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

 
  /*
  string msg ="GET http://g-ec2.images-amazon.com/images/G/01/social/api-share/amazon_logo_500500._V323939215_.png HTTP/1.1 \n"
    "Host: g-ec2.images-amazon.com\n"					\
    "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:59.0) Gecko/20100101 Firefox59.0\n" \
    "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/ /*;q=0.8\r\n" \
    "Accept-Language: en-US,en;q=0.5\n"				\
    "Accept-Encoding: gzip, deflate\n"				\
    "Connection: keep-alive\n"					\
    "Upgrade-Insecure-Requests: 1\n"					\
    "Pragma: no-cache\n"						\
    "Cache-Control: no-cache\n\n";
								      */
 
  
  int len = msg.size();
  void * buf = malloc(len + 1);
  for (int i = 0; i < 10; i++) {
    int bytes_sent = send(sockfd, msg.data(), len, 0);
    cout << "send: " << bytes_sent << endl;
    int length = recv(sockfd, buf, len, 0);
    cout << "received: " << len << endl;
			    cout << static_cast<char *> (buf) << endl;			    
  
  }
  //shutdown(sockfd, SHUT_RDWR);
  cout << "send over" << endl;

}

int main(void) {
  cout << "miaomiaomiao" << endl;
  string msg = readfile("test.txt");

  cout << msg;
  thread t1(send_request, msg);
  thread t2(send_request, msg);
  thread t3(send_request, msg);
  thread t4(send_request, msg);
  thread t5(send_request, msg);
  t1.detach();
  t2.detach();
  t3.detach();
  t4.detach();
  t5.detach();
  cout << "giaogiao" << endl;
  int i = 1;
  while(i){
    i = 1;
  }
}
