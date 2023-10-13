#include "MyDoubleVector.h"

// *** MYDOUBLEVECTOR TEST ***

// 2021203034 허찬영

int main() {
	// constructor test
	MyDoubleVector v1;
	MyDoubleVector v2;
	MyDoubleVector opt;
	MyDoubleVector copy;

	// push_back test
	for (size_t i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (size_t i = 10; i < 21; i++) {
		v2.push_back(i);
	}

	cout << "push_back test\n";
	cout << "v1: \n";
	for (size_t i = 0; i < 10; i++) {
		cout << v1[i] << '\n';
	}
	cout << "v2: \n";
	for (size_t i = 0; i < 10; i++) {
		cout << v2[i] << '\n';
	}

	// size and capacity test
	cout << "v1 size and v2 size test: " << v1.size() << ", " << v2.size() << '\n';
	cout << "v1 capacity and v2 capacity test: " << v1.capacity() << ", " << v2.capacity() << '\n';

	// pop_back test
	v2.pop_back();
	cout << "v1 size and v2 size test:  after pop_back: " << v1.size() << ", " << v2.size() << '\n';
	cout << "v1 capacity and v2 capacity test: after pop_back: " << v1.capacity() << ", " << v2.capacity() << '\n';

	// copy constructor test
	copy = v1;

	// clear and empty test
	copy.clear();
	cout << "clear and empty test(clear로 객체를 비우고 empty 함수로 확인): " << copy.empty() << endl;
	for (int i = 0; copy.size(); i++) {
		cout << copy[i] << '\n';
	}

	// operator test and index operator test
	opt = v1 + v2;
	cout << "operator+ test(opt = v1 + v2)\n";
	for (int i = 0; i < opt.size(); i++) {
		cout << opt[i] << '\n';
	}
	opt = v1 - v2;
	cout << "operator- test(opt = v1 - v2)\n";
	for (int i = 0; i < opt.size(); i++) {
		cout << opt[i] << '\n';
	}
	double d = v1 * v2;
	cout << "operator* test(product = v1 * v2)\n";
	cout << d << '\n';
	opt = -opt;
	cout << "operator- test(opt = -opt)\n";
	for (int i = 0; i < opt.size(); i++) {
		cout << opt[i] << '\n';
	}
	opt(7);
	cout << "operator() test(7로 변환)\n";
	for (int i = 0; i < opt.size(); i++) {
		cout << opt[i] << '\n';
	}
	opt += v1;
	cout << "operator+= test(opt += v1)\n";
	for (int i = 0; i < opt.size(); i++) {
		cout << opt[i] << '\n';
	}
	cout << "operator== test(opt == opt): ";
	if (opt == opt) {
		cout << "true\n";
	}
	else
		cout << "false\n";

	cout << "value of reserve(+=연산을 했기 때문에 opt의 현재 capacity는 200)\n";
	cout << "reserve test: ";
	opt.reserve(1001);
	cout << opt.capacity() << endl;

	return 0;
}