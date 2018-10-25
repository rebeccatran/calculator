#include <sstream>
#include <iostream>
#include "Division.h"
#include "ArithmeticExpression.h"
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;
Division::Division() {

}
Division::~Division() {

}
string Division::evaluate(){
	l = left -> evaluate();
	r = right -> evaluate();
	a  = atof(l.c_str());
	b = atof(r.c_str());
	divide = a / b;				// store a + b into addition
	ostringstream output; 
	output << divide;		// create an object called output that is of output string stream that holds addition
	return output.str();	// return  the addition as a string
}

void Division::print(){
	cout << "(";
	left->print();
	cout << " / "; // print the addition as a string into memory
	right->print();
	cout << ")";
}
