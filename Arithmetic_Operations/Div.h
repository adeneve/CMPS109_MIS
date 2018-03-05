#ifndef DIV_H
#define DIV_H
#include "ArithmeticOperation.h"
#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include <vector>
#include <map>

using namespace std;

class Div : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Div(vector<Type *> & MIS_Args); // copy the mis_vector

	Div();

	~Div();


	void execute(); // this will make use of the variable vector.

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    Keyword* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

};




#endif