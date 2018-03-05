/*
Henry Chang
hechang
Type.h
*/

#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>
#include <map>
#include "../File_Operations/Parser.h"
#include "../MIS/Keyword.h"

class Parser;

using namespace std;

class Type: virtual public Keyword {
private:
public:
	// Access Methods


	virtual  void getValue(void * ptr) = 0;

	virtual void getType(void * ptr) = 0;

	//for string only
	virtual char getChar(int index){};
	virtual void setChar(int index, char c){};
	virtual int getLength(){};

	// Manipulation Methods
	virtual void setValue( void* value_ptr) = 0;

	// Other
	virtual void initialize(vector<string> dataList, map<string, Type*>& typeVars, Parser * MISParser) = 0;
	virtual Keyword * clone(vector<string> dataList, map<string, Type*>& typeVars, Parser * MISParser) = 0;
	virtual void execute() = 0;
};
#endif //!TYPE_H
