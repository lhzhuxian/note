#ifndef _COMMON_H
#define _COMMON_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <err.h>


#include <aio.h>
#include <exception>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <unordered_map>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string>
#include <memory>
#include "http_parser.h"
#include <unistd.h>
#include <fstream>
#include <sstream>

typedef struct kevent kcb;
using namespace std;

#define BUFFNUM 3
#define BUFFSIZE 2000


const int g_max_event_count = 50;
const int g_backlog = 100;
const int g_maxthread = 4;
const int g_connec_tolerance = 100;

#endif
