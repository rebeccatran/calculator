#include <sstream>
#include <iostream>
#include "Multiplication.h"
#include "ArithmeticExpression.h"
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;
Multiplication::Multiplication() {

}
Multiplication::~Multiplication() {

}
string Multiplication::evaluate(){
	l = left->evaluate();
	r = right->evaluate();
	a = atof((l).c_str());
	b = atof((r).c_str());
	multiply = a * b;				// store a + b into addition
	ostringstream output; 
	output << multiply;	// create an object called output that is of output string stream that holds addition
	return output.str();				// return  the addition as a string

}

void Multiplication::print(){
	cout << "(";
	left->print();
	cout << " * ";
	right->print();
	cout << ")";
}

