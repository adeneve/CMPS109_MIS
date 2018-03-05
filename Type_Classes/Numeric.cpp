#include "Numeric.h"
#include <string>
#include <stdlib.h>

using namespace std;

Numeric::Numeric(){
	myType = 'N';
	name = "";
	number = 0;
	varMap = NULL;

}

Numeric::Numeric(string varName, int value){
	myType = 'N';
	name = varName;
	number = value;
}


Numeric::~Numeric(){
}

void Numeric::getValue(void * ptr) {
	int* intPtr = static_cast<int*>(ptr);
	*intPtr = number;

}

void Numeric::getType(void * ptr){
	char* charPtr = static_cast<char*>(ptr);
	*charPtr = myType;
}

void Numeric::setValue(void* value_ptr){
	int* intPtr = static_cast<int*>(value_ptr);
	number = *intPtr;
}

void Numeric::initialize(vector<string> dataList, map<string, Type*>& typeVars, Parser * MISParser){
	//mymap.insert ( std::pair<char,int>('a',100) )
	//map<string, Type*> vars = * typeVars;
	name = dataList[1];
	number = strtod(dataList[3].c_str(),NULL);
	typeVars[name] = this;
}

Keyword * Numeric::clone(vector<string> dataList, map<string, Type*>& typeVars, Parser * MISParser){
	Numeric * numeric = new Numeric();
	numeric->initialize(dataList, typeVars, NULL);
	return numeric;
}

void Numeric::execute(){
	
}
