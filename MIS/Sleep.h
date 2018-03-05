#ifndef SLEEP_H
#define SLEEP_H

#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Char.h"
#include "../Type_Classes/String.h"


#include <string>
#include <vector>

class Type;

class Sleep: public Keyword{
private:
	int Time;
public:
	// Constructor-Destructor
	Sleep();

	virtual ~Sleep();

	// Other
	void initialize(vector<string> dataList, map<string, Type*>& typeVars, Parser * MISParser);

	Keyword * clone(vector<string> dataList, map<string, Type*>& typeVars, Parser * MISParser);

	void execute();

};

#endif //SLEEP_H