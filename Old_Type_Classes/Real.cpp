#include "Real.h"
#include <string>

using namespace std;

Real::Real() {}

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


