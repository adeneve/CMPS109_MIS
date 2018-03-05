SRCS =  Server.cpp ../TCP/sources/TCPServerSocket.cpp ../TCP/sources/TCPSocket.cpp  ../File_Operations/*.cpp ../File_Operations/Jump/*.cpp ../Arithmetic_Operations/*.cpp ../Threading/Lock.cpp ../Threading/Barrier.cpp ../Threading/Unlock.cpp ../Threading/Thread_Begin.cpp ../Exceptions_Draft/*.cpp ../Type_Classes/*.cpp ../MIS/MIS.cpp ../MIS/Out.cpp ../MIS/Sleep.cpp
SRCS2 = ../TCP/sources/TCPServerSocket.cpp ../TCP/sources/TCPSocket.cpp Server.cpp
EXE = Server

all:${EXE}

${EXE}: ${SRCS}
	g++ -std=gnu++14 -ggdb ${SRCS} -pthread -o ${EXE}

clean:
	rm -f Server *.o
