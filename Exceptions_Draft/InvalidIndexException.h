/*
 * InvalidIndexException.h
 * Henry Chang
 */
#ifndef INVALIDINDEXEXCEPTION_H
#define INVALIDINDEXEXCEPTION_H

#include "stdlib.h"
#include <string>

class InvalidIndexException(string Estr): public exception{
private:
	string Error;
public:
	InvalidIndexException(string Estr);

	~InvalidIndexException() throw();

	const string what() const throw();
}

#endif // INVALIDINDEXEXCEPTION_H
