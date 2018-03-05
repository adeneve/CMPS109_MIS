//Threading_Keywords.h
//Abstract base class for all Threading keywords processed by the MIS

#ifndef THREADING_KEYWORD
#define THREADING_KEYWORD

#include <map>
#include <vector>
#include <string>
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "../Type_Classes/Type.h"
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

class Type;
class Parser;

class Threading_Keyword{
   public:
      virtual Threading_Keyword* clone(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars, ofstream* file) = 0;

      virtual void initialize(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id, map<string, int>* Locked_Vars, ofstream* file) = 0;
      virtual void execute() = 0;
      
};

#endif