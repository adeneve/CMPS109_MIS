//JumpZ.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream
//only if parameter passed in == 0;

#include "JumpZ.h"

using namespace std;

JumpZ::JumpZ(){}

bool JumpZ::jumpCondition(){
   return (this->val == 0);
}

Keyword* JumpZ::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpZ * jump = new JumpZ();
   jump->initialize(rawData,typeVars,P);
   return jump;
}

