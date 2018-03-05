//Label.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Sets a label a specific place in the input stream

#ifndef LABEL
#define LABEL

#include <string>
#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "Parser.h"

class Parser;

class Label: public Keyword{
   public:
      Label(int pos, std::string name);
      Label();
      int getPosition();
      std::string nameOf();
      virtual Keyword* clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
      virtual void initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P);
      virtual void execute();
   private:
      int position;
      std::string name;
      Parser* P;
};

#endif