//JumpZ.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream
//only if parameter passed in == 0;

#include "JumpNZ.h"

using namespace std;

JumpNZ::JumpNZ(){}

bool JumpNZ::jumpCondition(){
   return (this->val != 0);
}

Keyword* JumpNZ::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpNZ * jump = new JumpNZ();
   jump->initialize(rawData,typeVars,P);
   return jump;
}

