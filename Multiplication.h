#ifndef __MULTIPLICATION_H_		// header guard
#define __MULTIPLICATION_H_		// header guard
#include <string>		// necessary for function of code
#include "ArithmeticExpression.h"

using namespace std;
using std::string;

class Multiplication: public ArithmeticExpression{
public:
	Multiplication();
	virtual ~Multiplication();
	string evaluate();
	void print();
private:
	string l;
	string r;
	double a;
	double b;
	double multiply;

};

#endif
