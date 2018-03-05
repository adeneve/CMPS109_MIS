#havent tested this makefile..
SRC =  ArithmeticException.cpp testException.cpp

all: TestException

TestException: ${SRC}
	g++  ${SRC} -o TestException

clean:
	rm -f TestException

