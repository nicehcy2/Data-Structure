#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <vector>

// 소프트웨어학부 2021203034 허찬영 

using namespace std;

const char DECIMAL = '.';
const char RIGHT_PARENTHESIS = ')';
const char LEFT_PARENTHESIS = '(';
const char RIGHT_BRACE = '}';
const char LEFT_BRACE = '{';
const char RIGHT_BRACKET = ']';
const char LEFT_BRACKET = '[';

bool checkDividedByZero = false;

string EOI = "EOI";

string inToPos(const string);
bool getOrder(char, char);
bool checkPARENTHESIS(const string);
double computePostfix(const string);
vector<double> stringToVector(const string);

int main() {
	string infix;
	string postfix;
	double ans;

	while (true) {
		getline(cin, infix);

		if (!infix.compare(EOI))
			break;

		if (!checkPARENTHESIS(infix)) {	
			cout << "Error!: unbalanced parentheses\n";
			continue;
		}

		postfix = inToPos(infix);
		ans = computePostfix(postfix);
		if (checkDividedByZero == true) {
			cout << "Error!: divided by zero\n";
			checkDividedByZero = false;
			continue;
		}
		else {
			cout << fixed;
			cout.precision(3);
			cout << ans << '\n';
		}
	}
	
	return 0;
}

string inToPos(const string infix) {
	string postfix;
	stack<char> s;
	int	cnt = 0;

	while (infix[cnt] && infix[cnt] != '\0') {
		if (isdigit(infix[cnt]) || infix[cnt] == DECIMAL) {
			postfix.push_back(infix[cnt]);
			if (isdigit(infix[cnt + 1]) == 0 && infix[cnt + 1] != DECIMAL)
				postfix.push_back(' ');
			else if (infix[cnt + 1] == NULL)
				postfix.push_back(' ');
		}

		else if (infix[cnt] == LEFT_PARENTHESIS || infix[cnt] == LEFT_BRACE || infix[cnt] == LEFT_BRACKET) {
			s.push(infix[cnt]);
		}

		else if (infix[cnt] == '*') {
			if (s.empty()) {
				s.push('*');
			}
			else {
				if (getOrder(s.top(), infix[cnt])) {
					postfix.push_back(s.top());
					s.pop();
					postfix.push_back(' ');
				}
				s.push('*');
			}
		}

		else if (infix[cnt] == '/') {
			if (s.empty()) {
				s.push('/');
			}
			else {
				if (getOrder(s.top(), infix[cnt])) {
					postfix.push_back(s.top());
					s.pop();
					postfix.push_back(' ');
				}
				s.push('/');
			}
		}

		else if (infix[cnt] == '+') {
			if (s.empty()) {
				s.push('+');
			}
			else {
				if (getOrder(s.top(), infix[cnt])) {
					postfix.push_back(s.top());
					s.pop();
					postfix.push_back(' ');
				}
				s.push('+');
			}
		}

		else if (infix[cnt] == '-') {
			if (s.empty()) {
				s.push('-');
			}
			else {
				if (getOrder(s.top(), infix[cnt])) {
					postfix.push_back(s.top());
					s.pop();
					postfix.push_back(' ');
				}
				s.push('-');
			}
		}

		else if (infix[cnt] == RIGHT_PARENTHESIS) {
			while (s.top() != LEFT_PARENTHESIS) {
				postfix.push_back(s.top());
				s.pop();
				postfix.push_back(' ');
			}
			s.pop();
		}

		else if (infix[cnt] == RIGHT_BRACKET) {
			while (s.top() != LEFT_BRACKET) {
				postfix.push_back(s.top());
				s.pop();
				postfix.push_back(' ');
			}
			s.pop();
		}

		else if (infix[cnt] == RIGHT_BRACE) {
			while (s.top() != LEFT_BRACE) {
				postfix.push_back(s.top());
				s.pop();
				postfix.push_back(' ');
			}
			s.pop();
		}

		cnt++;
	}

	while (!s.empty()) {
		if (s.top() == LEFT_PARENTHESIS || s.top() == LEFT_BRACKET || s.top() == LEFT_BRACE)
			s.pop();
		else {
			postfix.push_back(s.top());
			s.pop();
			postfix.push_back(' ');
		}
	}

	return postfix;
}

bool getOrder(char oldStack, char newStack) {
	if (oldStack == LEFT_PARENTHESIS || oldStack == LEFT_BRACE || oldStack == LEFT_BRACKET)
		return false;

	if (newStack == '+' || newStack == '-')
		return true;
	else {
		if (oldStack == '*' || oldStack == '/')
			return true;
		else
			return false;
	}
}

bool checkPARENTHESIS(const string infix) {
	stack<char> s;
	int idx = 0;

	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == LEFT_PARENTHESIS || infix[i] == LEFT_BRACE || infix[i] == LEFT_BRACKET) {
			s.push(infix[i]);
		}

		else if (infix[i] == RIGHT_PARENTHESIS) {
			if (s.empty())
				return false;
			if (s.top() == LEFT_PARENTHESIS)
				s.pop();
		}

		else if (infix[i] == RIGHT_BRACE) {
			if (s.empty())
				return false;
			if (s.top() == LEFT_BRACE)
				s.pop();
		}

		else if (infix[i] == RIGHT_BRACKET) {
			if (s.empty())
				return false;
			if (s.top() == LEFT_BRACKET)
				s.pop();
		}
	}

	if (s.empty())
		return true;
	else
	{

	}
		return false;
}


double computePostfix(const string postfix) {
	string tmp;
	double result = 0.0;
	int cnt = 0;
	vector<double> operand = stringToVector(postfix);
	stack<double> numbers;

	for (int i = 0; i < postfix.length(); i++) {
		if (strchr("+-/*", postfix[i]) != NULL)
		{	
			double tmp;
			double num2 = numbers.top();
			numbers.pop();
			double num1 = numbers.top();
			numbers.pop();

			switch (postfix[i]) {
			case '+':
				tmp = num1 + num2;
				break;
			case '-':
				tmp = num1 - num2;
				break;
			case '*':
				tmp = num1 * num2;
				break;
			case '/':
				if (num2 == 0) {
					checkDividedByZero = true;
					return -1;
				}
				tmp = num1 / num2;
				break;
			}
			numbers.push(tmp);
		}

		else if ((isdigit(postfix[i]) || postfix[i] == DECIMAL) && postfix[i + 1] == ' ') {
			numbers.push(operand[cnt++]);
		}
	}
	result = numbers.top();
	numbers.pop();

	return result;
}

vector<double> stringToVector(const string postfix) {
	vector<double> operand;
	string tmp = "";

	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] == ' ') {
			if (tmp.size() == 0);
			else {
				operand.push_back(stod(tmp));
				tmp.clear();
			}
		}
		else if (isdigit(postfix[i]) || postfix[i] == DECIMAL) {
			tmp.push_back(postfix[i]);
		}
	}

	return operand;
}
