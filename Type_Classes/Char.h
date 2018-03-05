/*
Henry Chang
hechang
Char.h
*/
#ifndef CHAR_H
#define CHAR_H
#include <string>
#include <vector>
#include <map>
#include "Type.h"

using namespace std;

class Char : virtual public Type{
private:
	char value;
	string name;
	char myType;
	map<string, Type *> *varMap;
public:
	// Constructor-Destructor
	// Default Constructor
	Char();

	// Parameterized Constructor with name of Char and value
	Char(string varName, char value);

	// Destructor
	virtual ~Char();

	// Access Methods
	virtual void getValue(void * ptr);

	virtual void getType(void * ptr);

	// Manipulation Methods
	virtual void setValue(void * value);

	// Other
	virtual void initialize(vector<string> dataList, map<string, Type*> &typeVars, Parser* MIS_Parser);
	virtual Keyword * clone(vector<string> dataList, map<string, Type *> &typeVars, Parser* MIS_Parser);
	virtual void execute();
};
#endif // !CHAR_H
