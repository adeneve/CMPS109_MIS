#include "Add.h"
#include "Sub.h"
#include "Mult.h"
#include "Div.h"
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include <map>

using namespace std;

// tests the construction of Arithmetic Operations via Raw data arguments .. i.e -  ADD $myVar1, $myVar2, $myVar3....
int main(){

	//------------------------------------------------------------------------------------------------------
	// Add object clone

	map<string, Type*> Vars; // represents the variable storage in the MIS
	Vars["$myVar1"] = new Numeric("var1" , 20.1);
	Vars["$myVar2"] = new Numeric("var2", 30.1);
	Vars["$myVar3"] = new Numeric("var3", 4.1);
	Vars["$myVar4"] = new Numeric("var4", 1.1);


	vector<string> args; // string resembling .mis text
	args.push_back("ADD");
	args.push_back("$myVar1");
	args.push_back("$myVar2");
	args.push_back("$myVar3");
	args.push_back("$myVar4");
	args.push_back("1.1");

	// check the keyWord map with "ADD"
	
	//if ADD was found in the keyword map...
	ArithmeticOperation* keywordObj = new Add(); // should be KEYWORD*
	keywordObj = keywordObj->clone(args, Vars);
	try{
	keywordObj->execute();
} catch(exception& e){
	cout << e.what() << endl;
}

	int a = 0;
	Vars["$myVar1"]->getValue(&a);

	cout << a << endl;

	//--------------------------------------------------------------------------------------------------------------
	//Sub object clone

	vector<string> subArgs; // string resembling text 

	subArgs.push_back("SUB");
	subArgs.push_back("$myVar1"); // var1 is now 36.4 from before
	subArgs.push_back("$myVar2");
	subArgs.push_back("$myVar3");
	subArgs.push_back("$myVar4");
	subArgs.push_back("1.1");

	// check the keyWord map with "SUB"
	
	//if SUB was found in the keyword map...
	ArithmeticOperation* keywordObj2 = new Sub(); // should be KEYWORD*
	keywordObj2 = keywordObj2->clone(subArgs, Vars);
	try{
	keywordObj2->execute();  // should throw .. too many arguments.
}catch(exception& e){
	cout << e.what() << endl;
}

subArgs.pop_back();
subArgs.pop_back();

keywordObj2 = keywordObj2->clone(subArgs, Vars);

try{
	keywordObj2->execute();  // var1 = 30.1 - 4.1 = 26
}catch(exception& e){
	cout << e.what() << endl;
}


	int b = 0;

	Vars["$myVar1"]->getValue(&b);

	cout << "after subtraction .. 30.1 - 4.1"<< endl;
	cout << b << endl;

//---------------------------------------------------------------------------------------------------
// Mult object clone

	// check the keyWord map with "MULT"
	
	//if MULT was found in the keyword map...
	ArithmeticOperation* keywordObj3 = new Mult(); // should be KEYWORD*
	keywordObj3 = keywordObj3->clone(args, Vars); // using old Add arguments 30.1, 4.1, 1.1, 1.1
	try{
	keywordObj3->execute(); // 30 * 4
} catch(exception& e){
	cout << e.what() << endl;
}

	int c = 0;
	Vars["$myVar1"]->getValue(&c);

	cout << c << endl;

//-----------------------------------------------------------------------------------------------------
// Div object clone

	vector<string> divArgs; // string resembling text 

	divArgs.push_back("SUB");
	divArgs.push_back("$myVar1"); // var1 is now 36.4 from before
	divArgs.push_back("$myVar2");
	divArgs.push_back("$myVar3");
	divArgs.push_back("$myVar4");
	divArgs.push_back("1.1");

	// check the keyWord map with "Div"
	
	//if SUB was found in the keyword map...
	ArithmeticOperation* keywordObj4 = new Div(); // should be KEYWORD*
	keywordObj4 = keywordObj4->clone(subArgs, Vars);
	try{
	keywordObj4->execute();  // should throw .. too many arguments.
}catch(exception& e){
	cout << e.what() << endl;
}

divArgs.pop_back();
divArgs.pop_back();

keywordObj4 = keywordObj4->clone(subArgs, Vars);

try{
	keywordObj4->execute();  // var1 = 30 / 4 = 7
}catch(exception& e){
	cout << e.what() << endl;
}


	int d = 0;

	Vars["$myVar1"]->getValue(&d);

	cout << "after division .. 30 / 4"<< endl;
	cout << d << endl;
}