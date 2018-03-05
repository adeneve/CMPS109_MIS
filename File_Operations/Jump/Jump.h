//Jump.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in

#include "JumpOperation.h"

class Jump: public JumpOperation{
   public:
      Jump(std::string name, Parser* P);
      Jump();
      virtual bool jumpCondition();
      virtual Keyword* clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
      virtual void initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
};