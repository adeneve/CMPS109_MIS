//JumpCp.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if the logic specified is true -- Zero/Not Zero
//Abstract Base Class for these four operations

#ifndef JUMPZNZ
#define JUMPZNZ

#include <string>
#include "JumpOperation.h"
#include "../../Type_Classes/Numeric.h"
#include "../../Type_Classes/Real.h"

class JumpZNZ: public JumpOperation{
   public:
      virtual void initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
   protected:
      double val;
};

#endif