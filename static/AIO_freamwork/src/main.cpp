#include "connection.hpp"
#include <signal.h>

void HandleSigPipe(int snum) {
  return;
}

void HandleTermSig(int snum) {
  //
  return;
}




int g_listener = 0;
int g_kq = 0;


int ReadConfigFile(fstream cfd_file) {
  fstream cfgFile;
  cfgFile.open(cfgfilepath);
  if( ! cfgFile.is_open()) {
    cout<<"can not open cfg file!"<<endl;
    return false;
  }
  char tmp[1000];
  if(!cfg_file.eof()){
    cfg_file.getline(tmp,1000);
    string line(tmp);
    size_t pos = line.find('=');
    if(pos==string::npos) return -1;  
    int ans  = stoi(line.substr(pos+1));
    return ans;
  }
  return -1;
}



void AcceptConnection(int size)
{
  // Accept the connection
  for (int i = 0; i < size; i++) {
    int client = accept(g_listener, NULL, NULL);
    if (client == -1) {
      perror("Accept failed");
    }
    cout << "Connection " << client << " connectioned" << endl;
    Connection * connec = new Connection(client, g_kq);
    for (int i = 0; i < BUFFNUM; ++i) {
      void * tmpbuf = connec->ring_.get_buf_(i);
      ReadMessage * tmpmes = new ReadMessage(client, g_kq, 0, tmpbuf, i, connec);
      connec->ring_.set_message_(tmpmes, i);
      aio_read(tmpmes);
    }
  }
}

void HandleEvent(kcb * events, int nevents) {
   
  for (int i = 0; i < nevents; i++) {
    int sock = events[i].ident;
    int data = events[i].data;
    if (events[i].flags & EV_ERROR){
      cerr << "Event error: " << strerror(data) << endl;
    }
    
    
    if (sock == g_listener) {
      AcceptConnection(data);
    }
    else {
      
      Message * tmp = static_cast<Message*> (events[i].udata);
      // check whether read block or write block
      if (tmp->method_) {
	 if (aio_return(tmp) == -1){
	   perror("Write error:");
	 } 
	 tmp->connec_->ReturnWriteBlock();
	 //free(const_cast<void*> (tmp->aio_buf));
	 delete tmp;
      } else {
	ReadMessage * rtmp = static_cast<ReadMessage *> (events[i].udata);
	int ans = rtmp->ReceiveBlock();
	
	if(ans == 0) {
	  // connection closed 
	  delete rtmp;
	} else if (ans == -1) {
	  // all the read block has been freed, delete the connection

	  // cout << rtmp->connec_->fd_ << " closed" << endl;
	  delete rtmp->connec_;
	  delete rtmp;
	  
	}
      }
    }
  }
}




void Kfunction(){
  kcb events[g_max_event_count];

  cout << "ready" << endl;
  while(true) {
    int kn;
    
    kn = kevent(g_kq, NULL, 0, events, g_max_event_count, NULL);
    if(kn == -1) {
      // ignore EINTR
      if(errno != EINTR) {
	perror("kevent failed");
      }
      continue;
    }
    
    HandleEvent(events, kn);
    
  }
}


int main(void) {
  // read config
  fstream cfg_file;
  cfg_file.open("../config/parameter");
  if( ! cfg_file.is_open()) {
    cout<<"can not open cfg file!"<<endl;
    exit(-1);
  }
  g_max_event_count = ReadConfigFile(cfg_file);
  g_backlog = ReadConfigFile(cfg_file);
  g_maxthread = ReadConfigFile(cfg_file);
  g_connec_tolerance = ReadConfigFile(cfg_file);

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

  g_listener = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
  bind(g_listener, servinfo->ai_addr, servinfo->ai_addrlen);
  if(listen(g_listener, g_backlog) == -1) {
    perror("Listen failed: ");
    exit(-1);
  }

  // set up kqueue and register listener

  
  if((g_kq = kqueue()) == -1){
    perror("kqueue() failed");
    exit(EXIT_FAILURE);
  }
  kcb change;
  EV_SET(&change, g_listener, EVFILT_READ, EV_ADD, 0, 0, NULL);
  
  int ret = kevent(g_kq, &change, 1, NULL, 0, NULL);
  if (ret == -1) {
    perror("Falied in register listener");
    exit(EXIT_FAILURE);
  }
  if (change.flags & EV_ERROR) {
    errx(EXIT_FAILURE, "Event error: %s", strerror(change.data));
  }


  // Ignore SIGPIPE "Broken pipe" signals when socket connections are broken.
  signal(SIGPIPE, HandleSigPipe);
  
  // Register termination signals
  //  signal(SIGABRT, &HandleTermSig);
  // signal(SIGINT, &HandleTermSig);
  //signal(SIGTERM, &HandleTermSig);

  // set up threads and start running
  vector<thread> threadpool;
  try {
    
    for (int i = 0; i < g_maxthread; i++) {
      threadpool.push_back(thread(Kfunction));
      threadpool[i].detach();
    }
    Kfunction();
  } catch (const exception & e) {
    freeaddrinfo(servinfo);
  }
}