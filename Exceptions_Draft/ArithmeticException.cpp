#include "ArithmeticException.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// construct an Exception object and specify the type and specific error.
ArithmeticException:: ArithmeticException(string Estr): Error("Arithmetic Error: " + Estr) {}; // specific exception

ArithmeticException:: ~ArithmeticException() throw() {};

const char* ArithmeticException::what() const throw() {return Error.c_str();};


