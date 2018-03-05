#include "Unlock.h"

using namespace std;

void Unlock::initialize(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars, ofstream* file){
	if (args.size() != 2){
		// throw error
	}
	int temp_id = (*Locked_Vars)[args[1]];
	if (temp_id != thread_id){
		// throw error, not the same id
	}else{
	(*Locked_Vars)[args[1]] = 0;
	}
}

Threading_Keyword* Unlock::clone(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id,map<string, int>* Locked_Vars, ofstream* file){
	Threading_Keyword* Unlocker = new Unlock();
	Unlocker->initialize(args, variables, MIS_Parser, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars, file);
	return Unlocker;
}

void Unlock::execute(){}