/*
Henry Chang
hechang
Numeric.h
*/

#ifndef REAL_H
#define REAL_H
#include <string>
#include <vector>
#include <map>
#include "Type.h"

using namespace std;

class Real: virtual public Type{
private:
	double number;
	string name;
	char myType;
	map<string, Type *> *varMap;
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

	// Other
	virtual void initialize(vector<string> dataList, map<string, Type*> &typeVars, Parser* MIS_Parser);
	virtual Keyword * clone(vector<string> dataList, map<string, Type *> &typeVars, Parser* MIS_Parser);
	virtual void execute();
};

#endif // !NUMERIC_H

