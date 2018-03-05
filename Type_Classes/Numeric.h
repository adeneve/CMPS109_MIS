/*
Henry Chang
hechang
Numeric.h
*/

#ifndef NUMERIC_H
#define NUMERIC_H
#include <string>
#include <vector>
#include <map>
#include "Type.h"

#define VARIABLENAME 1
#define VARIABLEVALUE 2

using namespace std;

class Numeric: virtual public Type{
private:
	int number;
	string name;
	char myType;
	map<string, Type *> * varMap;
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

	// Other
	virtual void initialize(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser);
	virtual Keyword * clone(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser);
	virtual void execute();

};

#endif // !NUMERIC_H

