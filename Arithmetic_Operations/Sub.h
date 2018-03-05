#ifndef SUB_H
#define SUB_H
#include "ArithmeticOperation.h"
#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"

#include <vector>

using namespace std;

class Sub : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Sub(vector<Type *> & MIS_Args); // copy the mis_vector

	Sub();

	~Sub();


	void execute(); // this will make use of the variable vector.

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    Keyword* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

};




#endif