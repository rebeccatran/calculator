#include <sstream>
#include <iostream>
#include "Addition.h"
#include "ArithmeticExpression.h"
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;

Addition::Addition() {

}

Addition::~Addition() {

}

string Addition::evaluate(){
	l = left->evaluate();
	r = right->evaluate();
	a = atof((l).c_str());
	b = atof((r).c_str());
	addition = a + b;				// store a + b into addition
	ostringstream output;
	output << addition;	// create an object called output that is of output string stream that holds addition
	return output.str();
}

void Addition::print(){
	cout << "(";
	left->print();
	cout << " + "; // print the addition as a string into memory
	right->print();
	cout << ")";
}

