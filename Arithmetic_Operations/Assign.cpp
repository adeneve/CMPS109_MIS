#include "Assign.h"
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


void Assign::execute(){

	char type1;
	char type2;
	

	if(variables.size() != 2){
		throw(ArithmeticException("Assign takes in 2 arguments only"));
	}else{
		Type* first = variables[0];
	    Type* second = variables[1];
	    

	    first->getType(&type1);
	    second->getType(&type2);

	    if(type1 != type2){
	    	throw(ArithmeticException("arguments "));
	    }else{

	    	if(type1 == 'N'){
	    		int a = 0;
	    	second->getValue(&a);
	    	first->setValue(&a);
	    }
	    if(type1 == 'R'){
	    	double b = 0;
	    	second->getValue(&b);
	    	first->setValue(&b);
	    }
	    if(type1 == 'C'){
	    	char c;
	    	second->getValue(&c);
	    	first->setValue(&c);
	    }
	    if(type1 == 'S'){
	    	string d;
	    	second->getValue(&d);
	    	first->setValue(&d);
	    }
	    }

	}

}


void Assign::initialize(vector<string> args, map<string, Type*>& vars, Parser* MIS_Parser){
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
				if(a == 'N'){
				Type* literalN = new Numeric("tempN", strtod(word.c_str(), NULL));
				this->variables.push_back(literalN);
			}if(a == 'R'){
				Type* literalR = new Real("tempR", strtod(word.c_str(), NULL));
				this->variables.push_back(literalR);
			}
			if(a == 'C'){
				Type* literalC = new Char("tempC", word[0]);
				this->variables.push_back(literalC);
			}
			if(a == 'S'){
				Type* literalS = new String("tempS", word, 100);
				this->variables.push_back(literalS);
			}

		}
			
	}

}

Keyword* Assign::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	Assign* assign = new Assign();
	assign->initialize(args, variables, NULL);
	return assign;

}


Assign::Assign(){}

Assign::~Assign(){
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}