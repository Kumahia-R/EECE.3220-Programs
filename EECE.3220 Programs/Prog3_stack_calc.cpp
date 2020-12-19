#include <iostream>
#include <string>
#include <cctype>
#include "Node.h"
#include "Stack.h"

using namespace std;
int pemdas(char op) {
	if (op == '*' || op == '/') {
		return 2;
	}
	else {
		return 1;
	}
}
int operation(char operand, int int1, int int2) {
	switch (operand)
	{
	case '*':
		return int1 * int2;
		break;
	case '/':
		return int1 / int2;
		break;
	case '+':
		return int1 + int2;
		break;
	case '-':
		return int1 - int2;
		break;
	}
}
int postfixMath(string postfix)
{
	char intFirst, intSecond;
	int result;
	Stack<char> numbers;

	for (unsigned int i = 0; i < postfix.length(); i++)
	{
		if (postfix.at(i) >= '0' && postfix.at(i) <= '9')
		{
			numbers.push(postfix.at(i));
		}
		else if ((postfix.at(i)) == '*' || (postfix.at(i)) == '/' || (postfix.at(i)) == '+' || (postfix.at(i)) == '-' )
		{
			intSecond = numbers.getTop() - '0'; 
			numbers.pop();
			intFirst = numbers.getTop() - '0';
			numbers.pop();
			result = operation(postfix.at(i),intFirst, intSecond) + 48;
			numbers.push(result);
		}
	}
	result = numbers.getTop() - 48; 
	return result;
}

string postfix(string infix) {
	Stack<char> operators;
	string postfix;
	for (int i = 0; i < infix.size(); i++) {
		if (isdigit(infix.at(i))) {
			postfix.push_back(infix.at(i));
			postfix.push_back(' ');
		}
		else if (infix.at(i) == '(') {
			operators.push(infix.at(i));
		}
		
		else if (infix.at(i) == ')') {
			while (operators.getTop() != '(') {
				postfix.push_back(operators.getTop());
				postfix.push_back(' ');
				operators.pop();
			}
			operators.pop();
		}
		else if (infix.at(i) != ' ') {
			if (operators.empty() || pemdas(infix.at(i) >= pemdas(operators.getTop() || operators.getTop() == '('))) {
				operators.push(infix.at(i));
			}
			else {
				if (infix.at(i) != '+' || infix.at(i) != '-') {
					postfix.push_back(operators.getTop());
					operators.pop();
				}
				else {
					while (!operators.empty() && operators.getTop() != '(')
					{
						postfix.push_back(operators.getTop());
						postfix.push_back(' ');
						operators.pop();
					}
					postfix.push_back(infix.at(i));
					postfix.push_back(' ');
				}
			}
		}
	}
	while (!operators.empty())
	{
		postfix.push_back(operators.getTop());
		postfix.push_back(' ');
		operators.pop();
	}
	return postfix;
}
int main() {
	string infix;
	Stack<char> inDigits;
	while (infix != "exit") {
		cout << "Enter expression (or exit to end):\n";
		getline(cin, infix);
		string post = postfix(infix);
		if (infix.at(0) == '(' || isdigit(infix.at(0))) {
			cout << "Expression: " << infix << endl;
			cout << "Postfix form: " << post << endl;
			cout << "Result: " << postfixMath(post) << endl;
		}
		else if (infix.at(0) != 'e') {
			cout << "Invalid expression\n";
		}
	}
	cout << "Exiting program ...\n";
}