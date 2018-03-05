/*
Henry Chang
hechang
Numeric.h
*/

#ifndef NUMERIC_H
#define NUMERIC_H
#include <string>
#include "Type.h"

using namespace std;

class Numeric: public Type{
private:
	int number;
	string name;
	char myType;
public:

	

    // Constructor-Destructor
	// Default Constructor
	Numeric();

	// Parameterized Constructor with name of Numeric and value
	Numeric(string varName, int value);

	// Destructor
	virtual ~Numeric();

	// Access Methods
	virtual void getValue(void* ptr);

	virtual void getType(void* ptr);
	

	// Manipulation Methods
	virtual void setValue(void* value_ptr);
};

#endif // !NUMERIC_H

