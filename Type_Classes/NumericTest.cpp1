/*
Henry Chang
hechang
NumericTest.cpp
*/

#include "Numeric.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// getNumeric()
// return the Numeric value created by Numeric.h
int main(int argc, char* argv[]) {
	Numeric* num;
	string input = "10";
	string variable = "testInt";
	map<string, Type*> * mapStub;
	vector<string> vectorStub;
	Parser * parserStub = 0;
	int output;

	// initiating vectorStub
	vectorStub.push_back("Numeric");
	vectorStub.push_back(variable);
	vectorStub.push_back(input);

	cout << "Creating Numeric with default constructor." << endl;
	num = new Numeric();
	cout << "clone() and initialize()" << endl;
	num->clone(vectorStub, mapStub, parserStub);
	cout << "execute(): storing object into map in MIS" << endl;
	num->execute();
	cout << "execute() end" << endl;
	num->getValue(&output);
	cout << "value of Numeric is " << output << endl;
	cout << "value stored in map is" << (*mapStub)[variable] << endl;

	// Teardown
	delete num;
	/*output = num->getValue();
	num->setValue(20);
	cout << output << "\n";
	output = num->getValue();
	cout << output << "\n";
	delete num;
	return 0;*/
}
