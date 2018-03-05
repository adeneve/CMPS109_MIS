/*
Henry Chang
hechang
NumericTest.cpp
*/

#include "Numeric.h"
#include <iostream>
#include <string>

using namespace std;

// getNumeric()
// return the Numeric value created by Numeric.h
int main(int argc, char* argv[]) {
	Numeric* num;
	int input = 10;
	int output;
	string variable = "testInt";

	num = new Numeric( variable, input );
	/*output = num->getValue();
	num->setValue(20);
	cout << output << "\n";
	output = num->getValue();
	cout << output << "\n";
	delete num;
	return 0;*/
}