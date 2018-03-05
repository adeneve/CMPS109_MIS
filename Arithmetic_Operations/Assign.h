#ifndef ASSIGN_H
#define ASSIGN_H
#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "ArithmeticOperation.h"
#include <vector>
#include <map>

using namespace std;

class Assign : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Assign(vector<Type *> & MIS_Args); // copy the mis_vector

	Assign();

	~Assign();


    void execute(); // this will make use of the variable vector.

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    Keyword* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

};




#endif