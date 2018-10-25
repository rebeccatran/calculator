#include <sstream>
#include <iostream>
#include "Subtraction.h"
#include "ArithmeticExpression.h"
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;
Subtraction::Subtraction() {

}
Subtraction::~Subtraction() {

}
string Subtraction::evaluate(){
	l = left->evaluate();
	r = right->evaluate();
	a = atof((l).c_str());
	b = atof((r).c_str());
	subtraction = a - b;				// store a - b into subtraction
	ostringstream output; 				// initialize output as an output string stream value
	output << subtraction;				// create an object called output that is of output string stream that holds addition
	return output.str();				// return  the addition as a string

}

void Subtraction::print(){
	cout << "(";
	left->print();
	cout << " - "; 	// print the addition as a string into memory
	right->print();
	cout << ")";
}
