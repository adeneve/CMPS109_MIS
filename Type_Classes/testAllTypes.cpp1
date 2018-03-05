#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
#include "Type.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){

	Numeric StackNumeric("myStackN", 6);
	Numeric* myNumeric = new Numeric("HeapNum", 5);
	Type* myNumericT = new Numeric("TypePtrNumeric", 9);
	int a = 0;
	int b = 0;
	int c = 0;

	StackNumeric.getValue(&a);
	myNumeric->getValue(&b);
	myNumericT->getValue(&c);

	cout << a << endl; //6
	cout << b << endl; //5
	cout << c << endl; //9

    //------------------------------------------------------------------------
    //Reals
    
	Real StackReal("myStackR", 6.5);
	Real* myReal = new Real("HeapReal", 5.2);
	Type* myRealT = new Real("TypePtrReal", 9.4);
	double d = 0;
	double e = 0;
	double f = 0;

	StackReal.getValue(&d);
	myReal->getValue(&e);
	myRealT->getValue(&f);

	cout << d << endl;
	cout << e << endl;
	cout << f << endl;

	//-------------------------------------------------------------------------
	//Chars

	Char StackChar("myStackC", 'a');
	Char* myChar = new Char("HeapC", 'b');
	Type* myCharT = new Char("TypePtrC", 'c');
	char g = 0;
	char h = 0;
	char i = 0;

	StackChar.getValue(&g);
	myChar->getValue(&h);
	myCharT->getValue(&i);

	cout << g << endl;
	cout << h << endl;
	cout << i << endl;

	//---------------------------------------------------------------------------
	//Strings

	String StackString("myStackS", "this is a",100);
	String* myString = new String("HeapString", "this is b", 100);
	Type* myStringT = new String("TypePtrString", "this is c", 100);
	string j;
	string k;
	string l;

	StackString.getValue(&j);
	myString->getValue(&k);
	myStringT->getValue(&l);

	char x;
	char y;
	char z;

	x = StackString.getChar(8);
	y = myString->getChar(8);
	myStringT->setChar(8, 'w');
	z = myStringT->getChar(8);

	string setValueTestS = "new stack string";
	string setValueTestH = "new heap string";
	string setValueTestT = "new Type-declared string";

	StackString.setValue(&setValueTestS);
	myString->setValue(&setValueTestH);
	myStringT->setValue(&setValueTestT);

	cout << j << endl; // This is a
	cout << k << endl; // This is b
	cout << l << endl; // This is c

	cout << x << endl; // a
	cout << y << endl; // b
	cout << z << endl; // w

	StackString.getValue(&j);
	myString->getValue(&k);
	myStringT->getValue(&l);

	cout << j << endl; // new stack string
	cout << k << endl; // new heap string
	cout << l << endl; // new Type-declared string

	//Tear down
	delete myNumeric;
	delete myNumericT;
	delete myReal;
	delete myRealT;
	delete myChar;
	delete myCharT;
	delete myString;
	delete myStringT;
}
