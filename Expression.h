#ifndef __EXPRESSION_H_		// header guard
#define __EXPRESSION_H_		// header guard
#include <string>
#include <iostream>

using namespace std;
using std::string;

class Expression {
public:
	Expression();
	virtual ~Expression() {};
	virtual string evaluate()=0;
	virtual float convert(string s)=0;
	virtual void print()=0;

};

#endif
