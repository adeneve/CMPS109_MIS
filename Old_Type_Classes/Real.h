/*
Henry Chang
hechang
Numeric.h
*/

#ifndef REAL_H
#define REAL_H
#include <string>
#include "Type.h"

using namespace std;

class Real: public Type{
private:
	double number;
	string name;
	char myType;
public:

	

    // Constructor-Destructor
	// Default Constructor
	Real();

	// Parameterized Constructor with name of Numeric and value
	Real(string varName, double value);

	// Destructor
	virtual ~Real();

	// Access Methods
	virtual void getValue(void* ptr);

	virtual void getType(void* ptr);
	

	// Manipulation Methods
	virtual void setValue(void* value_ptr);
};

#endif // !NUMERIC_H

