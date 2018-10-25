#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "Subtraction.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Division.h"
#include "Number.h"
using namespace std;

bool validExpression(string expression) {
	/* Returns true if the expression is valid
	 * One operator for two values,
	 * equal number of opening and closing brackets
	 */
	int len = expression.length(); 						//Expression length
	int oBrack = 0, cBrack = 0, nums = 0, ops = 0;		//Valid characters
	int i = 0;											//Counter

	while (i < len) {									//Loop over expression
		char c = expression[i];							//Get character at index i
		char lastchar;									//Value of character at index i - 1
		char seclast;

		if (isspace(c)) {								//If the character is a whitespace
			//Do nothing
		}
		else if (c == '(') {
			if (lastchar == '-') {
				seclast = lastchar;
				ops --;
			}
			oBrack ++;
			seclast = lastchar;
			lastchar = c;
		}
		else if (c == ')') {
			cBrack ++;
			seclast = lastchar;
			lastchar = c;

		}
		else if (isdigit(c)) {
			if (i >= 1 and isdigit(expression[i-1])) {
				seclast = lastchar;
				lastchar = c;
			}
			else if (i >= 2 and (lastchar == '-' and seclast == '(')) {
				ops--;
				nums++;
				seclast = lastchar;
				lastchar = c;
			}
			else if (i > 2 and (isspace(lastchar) and isdigit(seclast))) {
				cout << "Expression not well formed" << endl;
				return false;
			}
			else {
				nums ++;
				seclast = lastchar;
				lastchar = c;
			}
		}
		else if (c == '*' or c == '/' or c == '+' or c == '-') {
			ops ++;
			seclast = lastchar;
			lastchar = c;

		}
		else {
			return false;
		}
 		i ++;

	}

	if (oBrack != cBrack) {
		cout << "Expression not well formed" << endl;
		return false;
	}
	if (nums != ops + 1) {
		cout << "Expression not well formed"<< endl;
		return false;
	}
	return true;

}
bool isOpMD(char c) {
	if (c == '*' or c == '/') {
		return true;
	}
	else {
		return false;
	}
}

bool isOpAS(char c) {
	if (c == '+' or c == '-') {
		return true;
	}
	else {
		return false;
	}
}

string removeWhitespace(string expression) {
	string:: iterator end_pos = std::remove(expression.begin(), expression.end(), ' ');
	expression.erase(end_pos, expression.end());
	return expression;
}

string simplify(string expression) {
	int len = expression.length();
	int ops = 0;
	int bracks = 0;

	for (int i = 0; i < len; ++i) {
		if (expression[i] == '(') {
			bracks ++;
		}
		if  (expression[i] == ')') {
			bracks --;
		}
		if( bracks == 0 and (isOpMD(expression[i]) or isOpAS(expression[i]))) {
			ops++;
		}
	}
	if (expression[0] == '(' and expression[len - 1]== ')' and ops == 0) {
		expression = expression.substr(1, len - 2);
	}
	return expression;
}


Expression* splitInTwo(string expression) {
	int len = expression.length();
	int i = len - 1;
	string l = "";
	string r = "";
	char op;
	int bracks = 0;
	int digits = 0;
	int ops;

	//Look for (+) and (-) operators
	while (i >= 0) {
		char c = expression[i];

		if (c == ')') {
			bracks ++;
		}
		else if (c == '(') {
			bracks--;
		}
		else if (isOpAS(c)) {
			ops++;
			if (bracks == 0) {
				op = c;
				if (i > 0) {
					l = expression.substr(0, i);
					r = expression.substr(i + 1, len);
				}

				if (op == '+') {
					Addition* exp = new Addition();
					exp->left = splitInTwo(simplify(l));
					exp->right = splitInTwo(simplify(r));
					return exp;

				}
				else {
					if (i > 0) {
						Subtraction* exp = new Subtraction();
						exp->left = splitInTwo(simplify(l));
						exp->right = splitInTwo(simplify(r));
						return exp;
					}
					else {
						Subtraction* exp = new Subtraction();
						exp->left = splitInTwo("0");
						exp->right = splitInTwo(simplify(expression.substr(1, len)));
						return exp;

					}

				}
			}

			else {

				// do nothing
			}

		}
		else if (isdigit(c)){
			digits++;
		}

		i --;
	}

	i = len - 1;
	//Look for (*) and (/) operators
	while (i >= 0) {
		char c = expression[i];

		if (c == '(') { 
			bracks ++;
		}
		else if (c == ')') {
			bracks --;
		}
		else if (isOpMD(c)) {
			ops++;
			if (bracks == 0) {
				op = c;
				l = expression.substr(0, i);
				r = expression.substr(i + 1, len);

				if (op == '*') {
					Multiplication* exp = new Multiplication();
					exp->left = splitInTwo(simplify(l));
					exp->right = splitInTwo(simplify(r));
					return exp;

				}
				else {
					Division* exp = new Division();
					exp->left = splitInTwo(simplify(l));
					exp->right = splitInTwo(simplify(r));
					return exp;
				}

			}
			else {

				// do nothing

			}
		}
		else if (isdigit(c)){
				digits++;
		}

		i--;
	}

	if (digits > 1) {
		Number* exp = new Number();
		exp->number = expression;
		return exp;
	}


	return NULL;
}

int main() {
	string input;
	vector<char> path;
	Expression* root;
	string result;
	while (input != "#") {
		cout << "Enter an expression:" << endl;
		getline(cin, input);
		if (input == "#") {
				cout << "Exiting" << endl;
		}
		else {
			if (validExpression(input)) {
				input = simplify(removeWhitespace(input));
				root = splitInTwo(input);
				result = root->evaluate();
				root->print();
				cout << " = " << fixed << setprecision(2) << root->convert(result) <<  endl;

				delete root;
			}
		}

	}

	return 0;
}







