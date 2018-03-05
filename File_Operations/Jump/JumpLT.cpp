//JumpLT.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream if first argument is less than second

#include "JumpLT.h"

JumpLT::JumpLT(){}

bool JumpLT::jumpCondition(){
   return (this->val1 < this->val2);
}

Keyword* JumpLT::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpLT * jump = new JumpLT();
   jump->initialize(rawData,typeVars,P);
   return jump;
}