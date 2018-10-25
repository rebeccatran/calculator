#ifndef __ArithmeticExpression__
#define __ArithmeticExpression__
#include "Expression.h"
#include <string>


using namespace std;
using std::string;


class ArithmeticExpression : public Expression{
public:
	ArithmeticExpression();
	virtual ~ArithmeticExpression();
	virtual string evaluate()=0;
	virtual void print()=0;
	float convert(string s);
	Expression *left;
	Expression *right;

private:
	string expression;

};

#endif
