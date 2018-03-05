SRC_C = ../TCP/sources/TCPSocket.cpp Client.cpp

all: Client

Client: ${SRC_C}
	g++ -std=gnu++14 ${SRC_C} -o Client

clean:
	rm -f Client

spotless: clean
	rm -f *.err *.out

.PHONY:
	clean spotless
