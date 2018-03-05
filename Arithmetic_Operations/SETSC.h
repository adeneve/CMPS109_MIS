#ifndef SETSC_H
#define SETSC_H
#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include "ArithmeticOperation.h"
#include <vector>
#include <map>

using namespace std;

class SETSC: public ArithmeticOperation{
private:
	vector<Type *> variables;
public:

	SETSC(vector<Type *> & MIS_Args);

	SETSC();
	~SETSC();

    void execute();

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    Keyword* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

};

#endif