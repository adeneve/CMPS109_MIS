#ty for the makefile model aaron
SRC = testAllTypes.cpp Numeric.cpp Real.cpp Char.cpp String.cpp

all: TypeTest

TypeTest: ${SRC}
	g++ -std=gnu++14  ${SRC} -o TypeTest

debug: ${SRC}
	echo << compiling with debugging info
	g++ -std=gnu++14 -ggdb  ${SRC} -o TypeTest
	echo << starting gdb
	gdb TypeTest

clean:
	rm -f  TypeTest