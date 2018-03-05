//JumpZ.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in

#include "JumpZNZ.h"

class JumpNZ: public JumpZNZ{
   public:
      JumpNZ ();
      virtual bool jumpCondition();
      virtual Keyword* clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
};