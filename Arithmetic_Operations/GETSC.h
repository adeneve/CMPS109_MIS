#ifndef GETSC_H
#define GETSC_H
#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "ArithmeticOperation.h"
#include <vector>
#include <map>

using namespace std;

class GETSC: public ArithmeticOperation{
private:
	vector<Type *> variables;
public:

	GETSC(vector<Type *> & MIS_Args);

	GETSC();
	~GETSC();

    void execute();

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    Keyword* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

};

#endif