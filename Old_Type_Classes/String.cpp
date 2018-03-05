/*
 * String.cpp
 * Henry Chang
 */

#include "String.h"
#include <string>

using namespace std;

String::String(){}

String::String(string varName, string value, int size){
	myType = 'S';
	name = varName;
	this->value = value;
	arraySize = size;
	length = value.length();
	sentenceSpace= (char *) calloc(arraySize, sizeof(char));

	for (int i = 0; i<value.length(); i++){
		sentenceSpace[i]=value[i];
	}
}

String::~String(){
	free(sentenceSpace);
}

void String::getValue(void* ptr){
	string* charPtr = static_cast<string*>(ptr);
	*charPtr = value;
}

void String::getType(void* ptr){
	char* charPtr = static_cast<char*>(ptr);
	*charPtr = myType;
}

int String::getLength(){
	return length;
}

char String::getChar(int index){
	if(index < 0 || index >= length){
		// throw invalidIndex exception
	}
	return sentenceSpace[index];
}

void String::setValue(void * ptr){
	string * charPtr = static_cast<string*>(ptr);
	value = *charPtr;

	for(int i = 0; i < value.length(); i++){
		sentenceSpace[i] = value[i];
	}
}

void String::setChar(int index, char c){
	if(index < 0 || index > length){
		// throw invalidIndex exception
	}else if(index == length){
		length++;
		sentenceSpace[index] = c;
	}
	sentenceSpace[index] = c;
}
