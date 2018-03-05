#ifndef ARITHMETICEXCEPTION_H
#define ARITHMETICEXCEPTION_H
#include <stdlib.h>
#include <string>

using namespace std;

class ArithmeticException : public exception {

private:

	string Error;

public:
	ArithmeticException(string Estr); //specific exception

	~ArithmeticException() throw(); // found this online, not sure what it means to add throw after a method.

	const char* what() const throw();
};

#endif