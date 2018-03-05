/*
 * Out.h
 * Henry Chang
 */
#ifndef OUT_H
#define OUT_H

#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"
#include "../Type_Classes/Char.h"
#include "../Type_Classes/String.h"


#include <string>
#include <vector>

class Type;

class Out: public Keyword{
private:
	ostringstream strStream;
	string outString;
	ostringstream targetValue;
	const char * singleQuote = "'";
	const char * doubleQuote = "\"";
   string filename;
public:
	// Constructor-Destructor
	Out();

	virtual ~Out();

	// Other
	void initialize(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser);

	Keyword * clone(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser);

	void execute();

	// Helper Methods
	void printVariable(string str, map<string, Type*> & typeVars);
	void printStringLiteral(string str);
	void printNumeralLiteral(string str);
};

#endif //OUT_H
