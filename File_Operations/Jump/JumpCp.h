//JumpCp.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if the logic specified is true -- Comparison Jump
//Logic can be GT(>) LT(<) GTE (>=) or LTE (<=)
//Abstract Base Class for these four operations

#ifndef JUMPCP
#define JUMPCP

#include <string>
#include "JumpOperation.h"
#include "../../Type_Classes/Numeric.h"
#include "../../Type_Classes/Real.h"

class JumpCp: public JumpOperation{
   public:
      virtual void initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
   protected:
      double val1, val2;
};

#endif