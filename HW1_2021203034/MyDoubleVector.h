#ifndef MYDOUBLEVECTOR_H
#define MYDOUBLEVECTOR_H

#include <iostream>
#include <cassert>
#include <cstdlib>

// 2021203034 ������

using namespace std;

class MyDoubleVector
{
private:
	size_t sz; // ũ��
	double* data; // ��Ҹ� ����Ű�� ������
	size_t init_capacity; // �Ҵ�� ������ ũ��

public:
	// *** CONSTRUCTORS ***

	MyDoubleVector();
	MyDoubleVector(const MyDoubleVector& v);
	~MyDoubleVector();

	// *** MEMBER_FUNCTIONS ***
	
	// init_capacity(�Ҵ�� ������ ũ��)�� ��ȯ�ϴ� �Լ�
	// Precondition: size_t Ÿ���� init_capacity�� ���� �Ǿ����.
	// Postcondition: init_capacity�� ���� ��ȯ��. ����� ��ȭ ����.
	size_t capacity() const;

	// size(����� ũ��)�� ��ȯ�ϴ� �Լ�
	// Precondition: size_t Ÿ���� sz�� ���� �Ǿ����.
	// Postcondition: sz�� ���� ��ȯ��. ����� ��ȭ ����.
	size_t size() const;

	// Removes the last element in the vector.
	// Precondition: �ϳ� �̻��� ��Ұ� �־�� ��.
	// Postcondition: ������ data�� ���� null�� �ʱ�ȭ �ǰ� sz�� ���� 1��ŭ �پ���.
	void pop_back();

	// Adds a new element at the end of the vector.
	// Precondition: double Ÿ���� ���� �־� �����.
	// Postcondition: data[sz]�� x�� �ʱ�ȭ �Ǽ� sz�� ���� 1��ŭ �þ��.
	void push_back(double x);

	// Reserve MyDoubleVector object's capacity of n.
	// Precondition: size_t Ÿ���� ���� �ʿ��ϰ� �Ű� ���� n�� ���� ������ �Ҵ� �������� Ŀ�� �Ѵ�.
	// Postcondition: ���ο� ������ �Ҵ�ǰ� init_capcity�� ���� n���� �ʱ�ȭ �ȴ�.
	void reserve(size_t n);

	// Returns whether the vector container is empty.
	// Precondition: �����ڰ� ���������� �۵��Ѵ�.
	// Postcondition: ��Ұ� ��������� true, �ƴϸ� false�� ��ȯ�Ѵ�.
	bool empty() const;

	// All the elements of the vector are dropped.
	// Precondition: �����ڰ� ���������� �۵��Ѵ�.
	// Postcondition: ��� ��Ұ� �����Ǹ� sz�� ���� 0���� �ʱ�ȭ �ȴ�.
	void clear();

	// *** OPERATORS ***
	
	// Copy Operator for Deep copy.
	// Precondition: Operands are MyDoubleVector. RHS has valid memory space and data.
	// Postcondition: LHS MyIntVector will have same elements with RHS.
	MyDoubleVector& operator=(const MyDoubleVector&);

	// Appends RHS object to LHS one.
	// Precondition: Operands are MyDoubleVector.
	// Postcondition: �ǿ������� ��ü�� ��Ұ� data�� ���ٿ�����. sz�� ���� �Ű������� sz��ŭ �����Ѵ�.
	void operator+=(const MyDoubleVector&);

	// Returns a reference to the element at the requested position in the vector container.
	// Precondition: idx�� ���� 0���� ũ�ų� ���� sz���� �۾ƾ� �Ѵ�.
	// Postcondition: data[idx]�� ���� ��ȯ�Ѵ�.
	double& operator[] (int idx);

	// Returns a reference to the element at the requested position in the vector container. (const version)
	// Precondition: idx�� ���� 0���� ũ�ų� ���� sz���� �۾ƾ� �Ѵ�.
	// Postcondition: data[idx]�� ���� ��ȯ�Ѵ�.
	double& operator[] (int idx) const;

	// ��� ����� ��ȣ�� �ٲ۴�.
	// Precondition: �����ڰ� ���������� �۵��Ѵ�.
	// Postcondition: ��� ����� ��ȣ�� �ٲ۴�.
	MyDoubleVector operator-();

	// Makes every element of this object be the value of the real-valued (double-typed) operand.
	// Precondition: int Ÿ���� �Ű������� �޴´�.
	// Postcondition: ��� ����� ���� n���� �ʱ�ȭ �Ѵ�.
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
	// Postcondition: ������ true, �ƴϸ� false�� ��ȯ�Ѵ�.
	bool operator==(const MyDoubleVector& v);

	// *** Static_Variable ***

	static const size_t Default_Capacity = 100; // vector�� �⺻ ũ��
};



#endif