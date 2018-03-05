#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
#include "../MIS/Keyword.h"
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include <map>

using namespace std;

int main(){

	//-------------------------------------------------------------------------------------------------------------------
	//Numeric clone

	map<string, Type*> Vars;

	vector<string> args; // string resembling .mis text
	args.push_back("NUMERIC");
	args.push_back("$myNum1");
	args.push_back("6");

	Vars["aNum"] = new Numeric("hi", 7);

	Keyword* myNumeric = new Numeric();
	myNumeric = myNumeric->clone(args, Vars, NULL);
	myNumeric->execute();

	Type* Num = Vars["$myNum1"];
	int a = 0;

	Type* Num1 = new Numeric("num", 4);
	Vars["$myNum"] = Num1;

	Type* Num2 = Vars["$myNum"];
	//Num1->getValue(&a);
	//Num->getValue(&a);

	//Type * Num5 = static_cast<Type*>(myNumeric);
	Num->getValue(&a);

	cout << Num << "number inside --> "<< a << endl;

	//-------------------------------------------------------------------------------------------------------------------
	//Real clone

	map<string, Type*> realVars;

	vector<string> realArgs; // string resembling .mis text
	realArgs.push_back("REAL");
	realArgs.push_back("$myReal1");
	realArgs.push_back("4.3");

	Keyword* myReal = new Real();
	myReal = myReal->clone(realArgs, realVars, NULL);
	myReal->execute();  

	Type* real1 = realVars["$myReal1"];
	double c = 0;

	real1->getValue(&c);

	cout << real1 << "number(double) inside --> "<< c << endl;

	//-------------------------------------------------------------------------------------------------------------------
	//Char clone

	map<string, Type*> charVars;

	vector<string> charArgs; // string resembling .mis text
	charArgs.push_back("CHAR");
	charArgs.push_back("$myChar1");
	charArgs.push_back("f");

	Keyword* myChar = new Char();
	myChar = myChar->clone(charArgs, charVars, NULL);
	myChar->execute();  

	Type* char1 = charVars["$myChar1"];
	char b = 0;

	char1->getValue(&b);

	cout << char1 << "char inside --> "<< b << endl;

	//------------------------------------------------------------------------------------------------------------------------
	//String clone



	map<string, Type*> stringVars;

	vector<string> stringArgs; // string resembling .mis text
	stringArgs.push_back("STRING");
	stringArgs.push_back("$myString1");
	stringArgs.push_back("100");
	stringArgs.push_back("Hello world");

	Keyword* myString = new String();
	myString = myString->clone(stringArgs, stringVars, NULL);
	myString->execute();  

	Type* string1 = stringVars["$myString1"];
	string d = "";

	string1->getValue(&d);

	cout << string1 << "string inside --> "<< d << endl;


}