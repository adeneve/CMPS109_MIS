//JumpCp.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if the logic specified is true -- Zero/Not Zero
// Abstract Base class for these classes

#include "JumpZNZ.h"

using namespace std;

void JumpZNZ::initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   char type;
   double val_R;
   int val_N;
   string var_name;
   Type *Var;
   bool temp_var=false;
   
   if (rawData.size() < 2) {
      //throw new expection ("not enough arugments")
      return;
   }
   
   this->name = rawData[1];
   this->P = P;
   var_name = rawData[2];
   
   //if argument names a variable
   if (typeVars[var_name] != NULL){  
      Var = typeVars[var_name];
   } else if(strtod(var_name.c_str(), NULL)) { // if argument is a literal
      Var = new Real("tempR", strtod(var_name.c_str(), NULL));
      temp_var = true;
   } else {
      //throw invalid argument type exception
      return;
   }
   
   Var->getType(&type);
   
   //type safety checking
   if (type == 'R'){
      Var->getValue(&val_R);
      this->val = val_R;
   } else if (type == 'N'){
      Var->getValue(&val_N);
      this->val = (double) val_N;
   } else {
      //throw invalid type exception
   }
   if (temp_var){
      delete (Var);
   }
}