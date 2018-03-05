#Makefile for Assignment 2, Problem 2
SRC = main.cpp File_Operations/*.cpp File_Operations/Jump/*.cpp Arithmetic_Operations/*.cpp Threading/*.cpp Exceptions_Draft/*.cpp Type_Classes/*.cpp MIS/MIS.cpp MIS/Out.cpp MIS/Sleep.cpp

all: MIS_x

MIS_x: ${SRC}
	g++ -std=gnu++14 ${SRC} -o MIS_x -pthread

debug: ${SRC}
	echo << compiling with debugging info
	g++ -std=gnu++14 -ggdb  ${SRC} -o MIS_x -pthread
	echo << starting gdb
	gdb MIS_x

clean:
	rm -f MIS_x MIS.err
