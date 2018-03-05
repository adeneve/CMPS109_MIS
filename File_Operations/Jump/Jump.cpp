//Jump.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream

#include "Jump.h"

using namespace std;

Jump::Jump(string name, Parser* P){
   this->P = P;
   this->name = name;
}

Jump::Jump(){
}

bool Jump::jumpCondition(){
   return true;
}

Keyword* Jump::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   Jump * jump = new Jump();
   jump->initialize(rawData,typeVars,P);
   return jump;
}

void Jump::initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   if (rawData.size() > 1){
      this->name = rawData[1];
      this->P = P;
   } else {
      //throw new SyntaxException()
   }
}