#include "Lock.h"

using namespace std;

void Lock::initialize(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars, ofstream* file){
	if (args.size() != 2){
		// throw error
	}else{
		(*Locked_Vars)[args[1]] = thread_id;
	}
}

Threading_Keyword* Lock::clone(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars, ofstream* file){
	Threading_Keyword* Locker = new Lock();
	Locker->initialize(args, variables, MIS_Parser, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars, file);
	return Locker;
}

void Lock::execute(){}