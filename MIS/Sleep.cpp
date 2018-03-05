#include "Sleep.h"
#include <iostream> 
#include <thread>
#include <chrono> 

Sleep::Sleep(){}

Sleep::~Sleep(){}


// arg 1 = string variable, arg 2 = variable or constant representing an index, a variable char
void Sleep::initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	char c;
	Type *Char,*String;

	if(args.size() != 2){
		// throw error
	}

	if(args[1][0] == '$'){
		if(variables[args[1]] != NULL){
			variables[args[1]]->getValue(&Time);

		}
	}else{
		Time = strtod(args[1].c_str(),NULL);
	}

}

Keyword* Sleep::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	Sleep* sleep = new Sleep();
    sleep->initialize(args, variables, NULL); // 3 args
    return sleep; 
}

void Sleep::execute(){
	std::this_thread::sleep_for (std::chrono::seconds(Time));
}