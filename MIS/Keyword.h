//Keyword.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//Abstract base class for all keywords processed by the MIS

#ifndef KEYWORD
#define KEYWORD

#include <map>
#include <vector>
#include <string>
#include "../File_Operations/Parser.h"
#include "../Type_Classes/Type.h"
#include <mutex>
#include <thread>

class Type;
class Parser;

class Keyword{
   public:
      virtual Keyword* clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P) = 0;
      virtual void initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P) = 0;
      virtual void execute() = 0;
      
   protected:
      std::map<std::string, Type*> *typeVars;
};

#endif
