/*
Henry Chang
hechang
String.h
*/
#ifndef STRING_H
#define STRING_H
#include <string>
#include <vector>
#include <map>
#include "Type.h"

using namespace std;

class String : virtual public Type {
private:
	int arraySize;
	int length;
	string value;
	string name;
	char myType;
	char * sentenceSpace;
	map<string, Type *> *typeMap;
public:
	// Constructor-Destructor
	// Default Constructor
	String();

	// Parameterized Constructor with name of String and value
	String(string varName, string value, int size);

	// Destructor
	virtual ~String();

	// Access Methods
	virtual void getValue(void * ptr);
	virtual void getType(void * ptr);
	virtual int getLength();
	virtual char getChar(int index);

	// Manipulation Methods
	virtual void setValue(void * ptr);

	virtual void setChar(int index, char c);

	// Other
	virtual void initialize(vector<string> dataList, map<string, Type*> &typeVars,Parser* MIS_Parser);
	virtual Keyword * clone(vector<string> dataList, map<string, Type *> &typeVars, Parser* MIS_Parser);
	virtual void execute();
};
#endif // !STRING_H


