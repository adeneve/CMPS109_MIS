#include "Sub.h"
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "../Exceptions_Draft/ArithmeticException.h"
#include <stdlib.h>
#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;

Sub::Sub(vector<Type *> & MIS_Args): variables(MIS_Args){ // copy the arguments into Add object variable vector
};


// iterate through the Type pointers, make reference of the first and do the operation on the others, put final val into first
void Sub::execute(){
	Type * first_arg; // using this to fetch the first argument as the one to change
	Type * second_arg;
	int globalCounter = 0;
	char type1;
	char type2;
	char otherType;
	double val = 0; // double for reals
	double val2 = 0;
	int Nval = 0; // ints for numerics
	int Nval2 = 0;

	if(variables.size() <= 2){
		throw(ArithmeticException("Not enough arguments"));
		return;
	}
	if(variables.size() >=4){
		throw(ArithmeticException("too many arguments"));
		return;
	}

	// iterate through argument pointers *it refers to the pointer/address, **it refers to the dereferenced object, in the case, int.
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		if(globalCounter == 0 ){
			first_arg = *it; // set temp to point to the first argument
			first_arg->getType(&type1);
			if(type1 != 'N' && type1 != 'R'){
				throw(ArithmeticException("Can only subtract numerics and reals"));
				return;
			}

		}
		if(globalCounter == 1){
			second_arg = *it;

			second_arg->getType(&type2);
			if(type2 != 'N' && type2 != 'R'){
				throw(ArithmeticException("Can only subtract numerics and reals"));
				return;
			}

		 // if numeric use an integer pointer
			if(type2 == 'N'){
			second_arg->getValue(&Nval);
			val = Nval;
		}else{
			second_arg->getValue(&val);
		}
		}
		else{
			Type* other_arg = *it; // dereference temp and subtract it with the next iteration dereferenced

			other_arg->getType(&otherType);
			if (otherType != 'N' && otherType != 'R'){
				throw(ArithmeticException("Can only subtract numerics and reals exclusively"));
				return;
			}

				if(otherType == 'N'){
				other_arg->getValue(&Nval2);
				val -= Nval2;
			}else{
				other_arg->getValue(&val2);
				val -= val2;
			}
				
			}
			
			
		
  		globalCounter += 1;
	}

	if(type1 == 'N'){
		Nval = val;
	first_arg->setValue(&Nval);
	}else{
		first_arg->setValue(&val);
	} 

	first_arg = NULL;
}

void Sub::initialize(vector<string> args, map<string, Type*>& vars, Parser* MIS_Parser){
	for(int i = 1; i < args.size(); i++){
		string word = args[i];
		char a;
		if(vars[word] != NULL){
			if(word[0] == '$'){ // if the argument is a variable
			Type* myType = vars[word];
			myType->getType(&a);
			this->variables.push_back(myType);
		}

		}
		if(word[0] == '$' && vars[word] == NULL){throw(ArithmeticException("variable not found"));}
		if(strtod(word.c_str(), NULL)){
				
				Type* literalR = new Real("tempR", strtod(word.c_str(), NULL));
				this->variables.push_back(literalR);

			}
			
	}

}

Keyword* Sub::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	Sub* sub= new Sub();
	sub->initialize(args, variables, NULL);
	return sub;

}

Sub::Sub(){}

Sub::~Sub(){
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}