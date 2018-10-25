#ifndef __DIVISION_H_		// header guard
#define __DIVISION_H_		// header guard
#include <string>		// necessary for function of code
#include "ArithmeticExpression.h"

using namespace std;
using std::string;

class Division: public ArithmeticExpression{
public:
	Division();
	virtual ~Division();
	string evaluate();
	void print();
private:
	double a;
	double b;
	string l;
	string r;
	double divide;

};
#endif
