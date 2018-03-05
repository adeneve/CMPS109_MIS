#ifndef ARITHMETICOPERATION_H
#define ARITHMETICOPERATION_H

#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include <vector>
#include <map>

using namespace std;

class ArithmeticOperation: public Keyword{

public:

	//virtual void doOperation() = 0; // pure virtual method. Needs to be implemented by all inheriters/children

	virtual void execute() = 0;

	virtual void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser) = 0;

	virtual Keyword* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser) = 0;
};


#endif