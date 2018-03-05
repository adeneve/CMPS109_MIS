#include <stdlib.h>
#include <vector>
#include <map>
#include <mutex>
#include <thread>

#include "IncludeAll.h"


using namespace std;

class Parser;
class Type;
class Keyword;
class Threading_Keyword;

class MIS{

private:
	Parser* MIS_Parser; // 1 parser for phase 1
	//map<int, Parser* > MIS_Parsers; // for multithreading
	map<string, Type* > MIS_variables; // a map structure for holding the names of our variables; should always be a Type*.
	map<string, Keyword *> Keyword_Factory; // a map structure which should be build at the start of the lifetime of the MIS; holds all keywords

	map<string, Threading_Keyword*> Thread_Factory;
	map<string, int > Locked_Vars;
	vector<thread> Threads;
	mutex m; // mutex to assure that threads don't change the same variables simultaneously 
	int Thread_id;
	bool resources_available;

public:

	MIS();
	~MIS();

	void makeParser(string fileName); // file name taken from user input

    void run(); // while parse has next line, if keyword is in keyword_Factory clone one and execute it.
};