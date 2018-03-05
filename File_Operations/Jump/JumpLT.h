//JumpLT.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream if first argument is less than second

#include "JumpCp.h"

class JumpLT: public JumpCp{
   public:
      JumpLT();
      virtual bool jumpCondition();
      virtual Keyword* clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
};