#include "ArithmeticException.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
// test

int addBelow100(int a, int b){

	if(a + b > 100){
		throw (ArithmeticException("too big"));
	}
	else return a;

}


int main(){
	try{
		//something not allowed
		addBelow100(500,400); // 
	}
	catch(exception& e){
		cout << e.what() << endl;
	}

}