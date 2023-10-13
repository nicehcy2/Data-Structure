#include "MyDoubleVector.h"

using namespace std;

// 2021203034 허찬영

// *** CONSTRUCTIRS ***

MyDoubleVector::MyDoubleVector() 
	:sz{ 0 }, data{ new double[Default_Capacity] }, init_capacity{ Default_Capacity }
{}

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v) 
	:sz{ v.sz }, data{ new double[v.init_capacity] }, init_capacity{ v.init_capacity }
{	
	copy(v.data, v.data + v.sz, data);
	//for(size_t i =0; i<v.sz; ++i) 
	//	data[i] = v.data[i];
}

MyDoubleVector::~MyDoubleVector() // Desturctor
{
	delete[] data;
}

// ***OPERATORS***

MyDoubleVector& MyDoubleVector::operator=(const MyDoubleVector& v) {
	if (this == &v)
		return *this;

	double* newPtr = new double[v.sz];
	copy(v.data, v.data + v.sz, newPtr);
	/*for (size_t i = 0; i < v.sz; i++) {
		newPtr[i] = v[i];
	}*/
	delete[] data;
	data = newPtr;
	sz = v.sz;
	init_capacity = v.init_capacity;

	return *this;
}

void MyDoubleVector::operator+=(const MyDoubleVector& v) {
	double* newPtr = new double[v.sz + sz];
	copy(this->data, this->data + this->sz, newPtr);
	copy(v.data, v.data + v.sz, newPtr + this->sz);
	/*for (size_t i = 0; i < sz; i++) {
		newPtr[i] = data[i];
	}
	for (size_t i = sz; i < sz + v.sz; ++i) {
		newPtr[i] = v.data[i - sz];
	}*/
	delete[] data;
	this->data = newPtr;
	this->sz = v.sz + sz;
	this->init_capacity = v.init_capacity *2;
}

MyDoubleVector MyDoubleVector::operator+(const MyDoubleVector& v) {
	assert(this->size() == v.size());

	MyDoubleVector sum(*this);
	for (int i = 0; i < sum.size(); i++) 
		sum.data[i] += v.data[i];
	return sum;
}

MyDoubleVector MyDoubleVector::operator-(const MyDoubleVector& v) {
	assert(this->size() == v.size());

	MyDoubleVector diff(*this);
	for (int i = 0; i < diff.size(); i++)
		diff.data[i] -= v.data[i];
	return diff;
}

double MyDoubleVector::operator*(const MyDoubleVector& v) {
	assert(this->size() == v.size());

	double sum = 0;
	MyDoubleVector product(*this);
	for (int i = 0; i < product.size(); i++)
		product.data[i] *= v.data[i];
	for (int i = 0; i < product.size(); i++) {
		sum += product.data[i];
	}
	return sum;
}

MyDoubleVector MyDoubleVector::operator-() {
	MyDoubleVector minus(*this);
	for (int i = 0; i < sz; i++) {
		if (minus.data[i] == 0);
		else
			minus.data[i] *= -1;
	}
	return minus;
}

bool MyDoubleVector::operator==(const MyDoubleVector& v) {
	if (this->size() == v.size()) {
		for (int i = 0; i < this->size(); i++) {
			if (v[i] != data[i]) {
				return false;
			}
		}
		return true;
	}
	else
		return false;
}

MyDoubleVector& MyDoubleVector::operator()(int n) {
	for (int i = 0; i < sz; i++) {
		this->data[i] = n;
	}
	return *this;
}

size_t MyDoubleVector::capacity() const {
	return init_capacity;
}

size_t MyDoubleVector::size() const {
	return sz;
}

double& MyDoubleVector::operator[](int idx) {
	assert(idx >= 0 && idx < sz);

	return data[idx];
}

double& MyDoubleVector::operator[](int idx) const {
	assert(idx >= 0 && idx < sz);

	return data[idx];
}

void MyDoubleVector::pop_back() {
	if (!this->empty()) {
		data[sz - 1] = '\0';
		sz--;
	}
}

void MyDoubleVector::push_back(double x) {
	if (init_capacity == 0)
		reserve(8); // 8개의 요소를 저장할 수 있는 공간으로 시작
	else if (sz == init_capacity)
		reserve(2 * init_capacity);
	data[sz] = x;
	sz++;
}

void MyDoubleVector::reserve(size_t n) {
	if (n <= init_capacity) return;
	double* newPtr = new double[n];
	for (size_t i = 0; i < sz; i++)
		newPtr[i] = data[i];
	delete[] data;
	data = newPtr;
	init_capacity = n;
}

bool MyDoubleVector::empty() const {
	if (sz == 0)
		return true;
	else 
		return false;
}

void MyDoubleVector::clear() {
	delete[] data;

	double* newData = new double[0];
	data = newData;
	sz = 0;
}
