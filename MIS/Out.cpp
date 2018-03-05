/*
 * Out.cpp
 * Henry Chang
 */

#include "Out.h"
#include <iostream>
#include <sstream>

using namespace std;

Out::Out(){
}

Out::~Out(){
}

void Out::initialize(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser){
	string token;
	for(int i = 1; i < dataList.size(); i++){
		token = dataList[i];
		if(token[0] == '$'){
			//cout << "Out.cpp printVariable()" << endl;
			printVariable(token, typeVars);
		}else if(token[0] == *singleQuote || token[0] == *doubleQuote){
           // cout << "Out.cpp printStringLiteral()" << endl;
			printStringLiteral(token);
		}else{ // numeral value
			//cout << "Out.cpp printNumeralLiteral()" << endl;
			printNumeralLiteral(token);
			cout<< endl;
		}
	}
   this->filename = MISParser->getName();
	outString = strStream.str();
}

Keyword * Out::clone(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser){
	Out * out = new Out();
	out->initialize(dataList, typeVars, MISParser);
	return out;
}

void Out::execute(){
   string out_name = this->filename + ".out";
   ofstream out_file; //open temporary file to store program output
   out_file.open(out_name, ofstream::app); //open file with append flag
   out_file << outString; //write output string to file
   out_file.close();
}

void Out::printVariable(string str, map<string, Type*> & typeVars){
   	 Type* first;
       char type1;
       string var;
       ostringstream convert;
       
       if (typeVars[str] != NULL){
         first = typeVars[str];
         first->getType(&type1);
       } else {
          //throw new argument exception
          cout << "Not a valid variable" << endl;
          return;
       }

	    if(type1 == 'N'){
         int a = 0;
	    	first->getValue(&a);
         convert << a;
         var = convert.str();
	    }
	    if(type1 == 'R'){
	    	double b = 0;
	    	first->getValue(&b);
         convert << b;
         var = convert.str();
	    }
	    if(type1 == 'C'){
	    	char c;
	    	first->getValue(&c);
         convert << c;
         var = convert.str();
	    }
	    if(type1 == 'S'){
	    	string d;
	    	first->getValue(&d);
         var = d;
	    }
  
	   strStream << var << endl;
}

void Out::printStringLiteral(string str){
	for(unsigned i = 1; i < str.length() - 1; i++){
		if(str.at(i) == '\\'){
			if(str.at(i+1) == 'n' || str.at(i+1) == 'b'){
				strStream << endl;
				i++;
				continue;
			}else if(str.at(i+1) == 't'){
				strStream << "    ";
				i++;
				continue;
			}
		}else{
		    strStream << str.at(i);
		}
	}
}

void Out::printNumeralLiteral(string str){
	strStream << str << endl;
}
