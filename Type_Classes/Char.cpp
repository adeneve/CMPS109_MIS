#include "Char.h"
#include <string>
#include <stdlib.h>

Char::Char(){
	myType = 'C';
	name = "";
	value = 0;
	varMap = NULL;
}

Char::Char(string varName, char value){
	myType = 'C';
	name = varName;
	this->value = value;
}

Char::~Char(){
}

// take in the address of a char, either dereference it to get a member of this object or set the value.
void Char::getValue(void * ptr){
	char* myChar = static_cast<char*>(ptr);
	*myChar = value;
}

void Char::getType(void * ptr){
	char* myChar = static_cast<char*>(ptr);
	*myChar = myType;

}

void Char::setValue(void * ptr){
	char* myChar = static_cast<char*>(ptr);
	value = *myChar;
}

void Char::initialize(vector<string> dataList, map<string, Type*> &typeVars, Parser* MIS_Parser){
	name = dataList[1];
	value = dataList[3][0]; // char
	typeVars[name] = this;

}

Keyword * Char::clone(vector<string> dataList, map<string, Type*> &typeVars, Parser* MIS_Parser){
	Char * character = new Char();
	character->initialize(dataList, typeVars, NULL);
	return character;
}

void Char::execute(){
	
}
