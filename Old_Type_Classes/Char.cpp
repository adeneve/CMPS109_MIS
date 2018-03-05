#include "Char.h"

Char::Char(){
}

Char::Char(string varName, char value){
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
	*myChar = value;

}

void Char::setValue(void * ptr){
	char* myChar = static_cast<char*>(ptr);
	value = *myChar;
}
