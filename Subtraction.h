#ifndef __SUBTRACTION_H_		// header guard
#define __SUBTRACTION_H_		// header guard
#include <string>				// necessary for function of code since working with string
#include "ArithmeticExpression.h"

using namespace std;
using std::string;

class Subtraction: public ArithmeticExpression{
public:
	Subtraction();	// initialize object Subtraction of given expression as a string
	virtual ~Subtraction();
	string evaluate();		// create evaluate as string type object
	void print();
private:
	string l;			// initialize the left side of the expression as a string for when we split at the operator
	string r;			// initialize the right side of the expression as a string for when we split
	double a;				// initialize a ( or the left side of the expression ) as a double, will make "left" convert to double a
	double b;				// initialize b ( or the right side of the expression ) as a double, will make "right" conver to double b
	double subtraction;		// initialize subtraction as a double

};

#endif
