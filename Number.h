#ifndef __NUMBER_H_
#define __NUMBER_H_
#include <string>
#include <iostream>
#include "ArithmeticExpression.h"

using namespace std;
using std::string;

class Number: public ArithmeticExpression {
public:
	Number();
	virtual ~Number();
	string evaluate();
	void print();
	string number;

};

#endif
