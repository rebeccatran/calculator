#include "Expression.h"
#include "ArithmeticExpression.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

ArithmeticExpression::ArithmeticExpression() {
	left = NULL;
	right = NULL;
}
ArithmeticExpression::~ArithmeticExpression() {
	delete left;
	delete right;
}
float ArithmeticExpression::convert(string s){
	float f;
	f = atof(s.c_str());
	return (float) f;

}


