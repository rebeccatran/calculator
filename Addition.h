#ifndef __ADD_H_		// header guard
#define __ADD_H_		// header guard
#include <string>		// necessary for function of code
#include "ArithmeticExpression.h"

using namespace std;
using std::string;

class Addition: public ArithmeticExpression{
public:
	Addition();
	virtual ~Addition();
	void print();
	string evaluate();
private:
	string l;
	string r;
	double a;
	double b;
	double addition;

};

#endif
