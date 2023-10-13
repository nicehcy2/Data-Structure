#ifndef MYDOUBLEVECTOR_H
#define MYDOUBLEVECTOR_H

#include <iostream>
#include <cassert>
#include <cstdlib>

// 2021203034 허찬영

using namespace std;

class MyDoubleVector
{
private:
	size_t sz; // 크기
	double* data; // 요소를 가리키는 포인터
	size_t init_capacity; // 할당된 영역의 크기

public:
	// *** CONSTRUCTORS ***

	MyDoubleVector();
	MyDoubleVector(const MyDoubleVector& v);
	~MyDoubleVector();

	// *** MEMBER_FUNCTIONS ***
	
	// init_capacity(할당된 영역의 크기)를 반환하는 함수
	// Precondition: size_t 타입의 init_capacity가 정의 되어야함.
	// Postcondition: init_capacity의 값이 반환됨. 요소의 변화 없음.
	size_t capacity() const;

	// size(요소의 크기)를 반환하는 함수
	// Precondition: size_t 타입의 sz가 정의 되어야함.
	// Postcondition: sz의 값이 반환됨. 요소의 변화 없음.
	size_t size() const;

	// Removes the last element in the vector.
	// Precondition: 하나 이상의 요소가 있어야 함.
	// Postcondition: 마지막 data의 값이 null로 초기화 되고 sz의 값이 1만큼 줄어든다.
	void pop_back();

	// Adds a new element at the end of the vector.
	// Precondition: double 타입의 값을 넣어 줘야함.
	// Postcondition: data[sz]가 x로 초기화 되서 sz의 값이 1만큼 늘어난다.
	void push_back(double x);

	// Reserve MyDoubleVector object's capacity of n.
	// Precondition: size_t 타입의 값이 필요하고 매개 변수 n의 값이 기존의 할당 영역보다 커야 한다.
	// Postcondition: 새로운 공간이 할당되고 init_capcity의 값이 n으로 초기화 된다.
	void reserve(size_t n);

	// Returns whether the vector container is empty.
	// Precondition: 생성자가 정상적으로 작동한다.
	// Postcondition: 요소가 비어있으면 true, 아니면 false를 반환한다.
	bool empty() const;

	// All the elements of the vector are dropped.
	// Precondition: 생성자가 정상적으로 작동한다.
	// Postcondition: 모든 요소가 해제되며 sz의 값이 0으로 초기화 된다.
	void clear();

	// *** OPERATORS ***
	
	// Copy Operator for Deep copy.
	// Precondition: Operands are MyDoubleVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have same elements with RHS.
	MyDoubleVector& operator=(const MyDoubleVector&);

	// Appends RHS object to LHS one.
	// Precondition: Operands are MyDoubleVector.
	// Postcondition: 피연산자의 객체의 요소가 data에 덧붙여진다. sz의 값이 매개변수의 sz만큼 증가한다.
	void operator+=(const MyDoubleVector&);

	// Returns a reference to the element at the requested position in the vector container.
	// Precondition: idx의 값이 0보다 크거나 같고 sz보다 작아야 한다.
	// Postcondition: data[idx]의 값을 반환한다.
	double& operator[] (int idx);

	// Returns a reference to the element at the requested position in the vector container. (const version)
	// Precondition: idx의 값이 0보다 크거나 같고 sz보다 작아야 한다.
	// Postcondition: data[idx]의 값을 반환한다.
	double& operator[] (int idx) const;

	// 모든 요소의 부호를 바꾼다.
	// Precondition: 생성자가 정상적으로 작동한다.
	// Postcondition: 모든 요소의 부호를 바꾼다.
	MyDoubleVector operator-();

	// Makes every element of this object be the value of the real-valued (double-typed) operand.
	// Precondition: int 타입의 매개변수를 받는다.
	// Postcondition: 모든 요소의 값을 n으로 초기화 한다.
	MyDoubleVector& operator()(int n);

	// Returns an object that is a vector-sum of the two operand objects.
	// Precondition: Operands are MyDoubleVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have same elements with RHS.
	MyDoubleVector operator+(const MyDoubleVector& v);

	// Returns an object that is a vector-difference of the two operand objects.
	// Precondition: Operands are MyDoubleVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have same elements with RHS.
	MyDoubleVector operator-(const MyDoubleVector& v);

	// Returns the scalar product (or dot product) value of the two operand objects.
	// Precondition: Operands are MyDoubleVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have same elements with RHS.
	
	//MyDoubleVector operator*(const MyDoubleVector& v);
	double operator*(const MyDoubleVector& v);

	// Returns whether or not the two operand vectors are the same.
	// Precondition: Operands are MyDoubleVector.
	// Postcondition: 같으면 true, 아니면 false를 반환한다.
	bool operator==(const MyDoubleVector& v);

	// *** Static_Variable ***

	static const size_t Default_Capacity = 100; // vector의 기본 크기
};



#endif