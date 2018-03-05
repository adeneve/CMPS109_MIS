/*
Henry Chang
hechang
String.h
*/
#ifndef STRING_H
#define STRING_H
#include <string>
#include "Type.h"

using namespace std;

class String : public Type {
private:
	int arraySize;
	int length;
	string value;
	string name;
	char myType;
	char * sentenceSpace;
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
};
#endif // !STRING_H


