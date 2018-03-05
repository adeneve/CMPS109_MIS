//JumpLTE.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream if first argument is less than or equal to 

#include "JumpLTE.h"

JumpLTE::JumpLTE(){}

bool JumpLTE::jumpCondition(){
   return (this->val1 <= this->val2);
}

Keyword* JumpLTE::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpLTE * jump = new JumpLTE();
   jump->initialize(rawData,typeVars,P);
   return jump;
}