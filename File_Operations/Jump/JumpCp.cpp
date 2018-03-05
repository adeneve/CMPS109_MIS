//JumpCp.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if the logic specified is true -- Comparison Jump
//Logic can be GT(>) LT(<) GTE (>=) or LTE (<=)

#include "JumpCp.h"
#include <iostream>

using namespace std;

void JumpCp::initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   char type1,type2;
   double val1_R,val2_R, val1,val2;
   int val1_N,val2_N;
   string var1_name, var2_name;
   Type *Var1,*Var2;
   bool var1_temp=false,var2_temp=false;
   
   if (rawData.size() < 3) {
      //throw new expection ("not enough arugments")
      return;
   }
   
   this->name = rawData[1];
   this->P = P;
   var1_name = rawData[2];
   var2_name = rawData[3];
   
   //if argument names a variable
   if (typeVars[var1_name] != NULL){  
      Var1 = typeVars[var1_name];
   } else if(strtod(var1_name.c_str(), NULL)) { // if argument is a literal
      Var1 = new Real("tempR", strtod(var1_name.c_str(), NULL));
      var1_temp = true;
   } else {
      //throw invalid argument type exception
   }
   
   if (typeVars[var2_name] != NULL){  
      Var2 = typeVars[var2_name];
   } else if(strtod(var2_name.c_str(), NULL)) {
      Var2 = new Real("tempR", strtod(var2_name.c_str(), NULL));
      var2_temp=true;
   } else {
      //throw invalid argument type excpetion
   }
   
   Var1->getType(&type1);
   Var2->getType(&type2);
   
   //type safety checking
   if (type1 == 'R'){
      Var1->getValue(&val1_R);
      this->val1 = val1_R;
   } else if (type1 == 'N'){
      Var1->getValue(&val1_N);
      this->val1 = (double) val1_N;
   } else {
      //throw invalid type exception
   }
   
   if (type2 == 'R'){
      Var2->getValue(&val2_R);
      this->val2 = val2_R;
   } else if (type2 == 'N'){
      Var2->getValue(&val2_N);
      this->val2 = (double) val2_N;
   } else {
      //throw invalid type exception
   }
   
   if (var1_temp){
      delete (Var1);
   }
   if (var2_temp){
      delete (Var2);
   }
   
}