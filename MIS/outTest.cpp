/*
 * outTest.cpp
 * Henry Chang
 */

#include "Out.h"
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"
#include "../Type_Classes/Char.h"
#include "../Type_Classes/String.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
	// Declaration
	Out * testTarget;
	map<string, Type*> mapStub;
	vector<string> vectorStub;
	vector<string> lineVector;
	int first = 1;
	double second = 2.5;
	char third = '3';
	string fourth = "four";

	// lineVector
	lineVector.push_back("")

	// Variable Storage Setup
	cout << "creating first Numeric Object" << endl;
	Numeric First = new Numeric();
	First->clone(lineVector);

	cout << "setting value to object" << endl;
	mapStub["$first"]->setValue(&first);
	cout << "first Numeric Object complete" << endl;
	cout << "creating Real Object" << endl;
	mapStub["$second"] = new Real();
	cout << "setting value to object" << endl;
	mapStub["$second"]->setValue(&second);
	cout << "creating Char Object" << endl;
	mapStub["$third"] = new Char();
	cout << "setting Char value" << endl;
	mapStub["$third"]->setValue(&third);
	cout << "creating String Object" << endl;
	mapStub["$fourth"] = new String();
	cout << "setting String value" << endl;
	mapStub["$fourth"]->setValue(&fourth);
	cout << "map setup complete" << endl;

	// Input Vector Setup
	cout << "pushing to vector" << endl;
	vectorStub.push_back("OUT");
	vectorStub.push_back("$first");
	vectorStub.push_back("$second");
	vectorStub.push_back("$third");
	vectorStub.push_back("3.5");
	vectorStub.push_back("back of vector");

	// Test
	testTarget = new Out();
	cout << "Out->clone()" << endl;
	testTarget = static_cast<Out*>(testTarget->clone(vectorStub, mapStub, NULL));
	cout << "Out->clone() end" << endl;
	cout << "printing to cout" << endl;
	testTarget->execute(); // 1
	                       // 2.5
	                       // 3
	                       // 3.5
	                       // four
	                       // 4.5
	cout << "printing end" << endl;

	return 0;
}
