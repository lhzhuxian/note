CC=g++49
SCL=-lc
C11=-std=c++11
CFLAGS= -gdwarf-2 -gstrict-dwarf -Wall -Wextra -g
THREAD= -pthread
ALL: server connection.o request.o
#test2: test2.cpp
#	$(CC) -o test2 test2.cpp $(SCL) $(C11) $(CFLAGS) $(THREAD)	
#client: client.cpp 
#	$(CC) -o client client.cpp $(SCL) $(C11) $(CFLAGS) $(THREAD)
server: main.cpp connection.o request.o
	$(CC) -o server main.cpp connection.o request.o http_parser.o  $(SCL) $(C11) $(CFLAGS) $(THREAD)
connection.o: connection.cpp
	$(CC) -c connection.cpp $(SCL) $(C11) $(CFLAGS)
request.o: request.cpp
	$(CC) -c request.cpp $(SCL) $(C11) $(CFLAGS)
clean:
	rm -f server connection.o client request.o ring_buff.o test2
