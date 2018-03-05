#include <iostream>
#include "Type.h"
#include "Numeric.h"

int main(){

	string type;
	int a=0;
	char c = 'a';
	string name = "mynum";

	Type * myNumeric = new Numeric(name, 27);

	type = "boo";

	myNumeric->getValue(&a);

	std::cout << a  << std::endl;

	myNumeric->getType(&c);

    int b = 65;

	myNumeric->setValue(&b);

	myNumeric->getValue(&a);



    std::cout << a  << std::endl;
    
    std::cout << c << std::endl;

}