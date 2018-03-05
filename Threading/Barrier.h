#ifndef BARRIER_H
#define BARRIER_H

#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "Threading_Keyword.h"
#include <vector>
#include <map>
#include <stdlib.h>
#include <thread>
#include <mutex>


using namespace std;

class Barrier : public Threading_Keyword{
private:
	vector<string> instructions; 
	map<string, Type *> * Mis_Vars;

	map<string, Keyword *> Keyword_Factory;

	//thread Factory_Thread;
public:
	

    void initialize(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars,ofstream* file);

    Threading_Keyword* clone(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars,ofstream* file);

    void execute();

   // void runThread(map<string, Keyword*>& Keyword_Factory,map<string, Type*>& variables,mutex& m, vector<thread>& threads);

};




#endif