#include "Sleep.h"
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"
#include "Keyword.h"
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include <map>


int main(){

	//------------------------------------------------------------------------------------------------------
	// Sleep object clone

	map<string, Type*> Vars; // represents the variable storage in the MIS
	Vars["$myVar1"] = new Numeric("var1" , 5.1);
	Vars["$myVar2"] = new Real("var2", 30.1);
	Vars["$myVar3"] = new Real("var3", 4.5);
	Vars["$myVar4"] = new Numeric("var4", 4.3);


	vector<string> args; // string resembling .mis text
	args.push_back("SLEEP");
	args.push_back("$myVar1");

	// check the keyWord map with "ADD"
	
	//if ADD was found in the keyword map...
	Keyword* keywordObj = new Sleep(); // should be KEYWORD*
	keywordObj = keywordObj->clone(args, Vars, NULL);
	try{
	keywordObj->execute();
} catch(exception& e){
	cout << e.what() << endl;
}


	int a = 0;
	Vars["$myVar1"]->getValue(&a);

	cout << a << endl;
}