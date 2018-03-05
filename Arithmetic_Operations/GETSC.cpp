#include "GETSC.h"
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"
#include "../Type_Classes/Char.h"
#include "../Type_Classes/String.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "../Exceptions_Draft/ArithmeticException.h"
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include <map>
#include <iostream>



//using namespace std;

GETSC::GETSC(){}

GETSC::~GETSC(){}


// arg 1 = string variable, arg 2 = variable or constant representing an index, a variable char
void GETSC::initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	int index;
	char c;
	Type *Char,*String;

	if(args[2][0] == '$'){
		if(variables[args[2]] != NULL){
			variables[args[2]]->getValue(&index);

		}
	}else{
		index = strtod(args[2].c_str(),NULL);
	}
	if(args[3][0] == '$'){
		if(variables[args[3]] != NULL){
			Char = variables[args[3]];

		}
	}else{
		// throw 3rd argument needs to be a variable
      cout << "Third Argument is not a Variable" << endl;
	}
	if(args[1][0] == '$'){
		if(variables[args[1]] != NULL){
         String = variables[args[1]];
			c = String->getChar(index);
			Char->setValue(&c);

		}
	}

}

Keyword* GETSC::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	GETSC* GSC = new GETSC();
    GSC->initialize(args, variables, NULL); // 3 args
    return GSC; 
}

void GETSC::execute(){}