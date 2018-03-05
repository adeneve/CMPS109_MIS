//JumpGTE.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream if first argument is greater than or equal to second

#include "JumpGT.h"

JumpGT::JumpGT(){}

bool JumpGT::jumpCondition(){
   return (this->val1 > this->val2);
}

Keyword* JumpGT::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpGT * jump = new JumpGT();
   jump->initialize(rawData,typeVars,P);
   return jump;
}