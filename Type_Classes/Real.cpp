#include "Real.h"
#include <string>
#include <stdlib.h>

using namespace std;

Real::Real() {
	myType = 'R';
	name = "";
	number = 0;
	varMap = NULL;
}

Real::Real(string varName, double value) {
	myType='R';
	name = varName;
	number = value;
}

Real::~Real() {
}

void Real::getValue(void * ptr) {
	double* DPtr = static_cast<double*>(ptr);
	*DPtr = number;
}

void Real::getType(void * ptr){
	char* charPtr = static_cast<char*>(ptr);
	*charPtr = myType;
}

void Real::setValue(void * ptr) {
	double* DPtr = static_cast<double*>(ptr);
	number = *DPtr;
}

void Real::initialize(vector<string> dataList, map<string, Type*> &typeVars, Parser* MIS_Parser){
	name = dataList[1];
	number = strtod(dataList[3].c_str(),NULL);
	typeVars[name] = this;
}

Keyword * Real::clone(vector<string> dataList, map<string, Type*> &typeVars, Parser* MIS_Parser){
	Real * real = new Real();
	real->initialize(dataList, typeVars, NULL);
	return real;
}

void Real::execute(){
	
}
