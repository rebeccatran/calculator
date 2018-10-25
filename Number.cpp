#include <sstream>
#include <iostream>
#include "Number.h"
#include "ArithmeticExpression.h"
#include <string>
#include <stdlib.h>

using namespace std;
using std::string;
Number::Number() {

}
Number::~Number() {

}

string Number::evaluate() {
	return number;
}

void Number::print() {
	cout << number;
}
