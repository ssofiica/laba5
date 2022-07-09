#pragma once
#ifndef MYSET_H
#define MYSET_H
#include <iostream>
#include "MyVector.h"
using namespace std;

template<class T>
class MySet :public MyVector<T>
{
public:
	MySet(T el) :MyVector<T>(el) {};
	MySet() :MyVector<T>() {};
	MySet operator+(const MySet& s2);
	MySet operator-(const MySet& s2);
	MySet operator*(const MySet& s2);
	bool operator==(MySet& s);
	MySet& operator+=(MySet& s);
	MySet& operator-=(MySet& s);
	MySet& operator*=(MySet& s);
	void add_element(T el);
	void delete_element(T el);
	bool is_element(T el);
};
template<class T>
MySet<T> MySet<T>::operator+(const MySet<T>& s2) {
	MySet<T> sum = *this;
	for (int i = 0; i < s2.MyVector<T>::Size(); i++) {
		if (!sum.is_element(s2[i])) sum.add_element(s2[i]);
	}
	return sum; 
}
template<class T>
MySet<T> MySet<T>::operator*(const MySet<T>& s2) {
	MySet<T> mp;
	MySet<T> tmp = *this;
	for (int i = 0; i < s2.MyVector<T>::Size(); i++) {
		if (tmp.is_element(s2[i])) mp.add_element(s2[i]);
	}
	return mp;
}
template<class T>
MySet<T> MySet<T>::operator-(const MySet<T>& s2) {
	MySet<T> dif = *this;
	for (int i = 0; i < s2.MyVector<T>::Size(); i++) {
		if (dif.is_element(s2[i])) dif.delete_element(s2[i]);
	}
	return dif;
}
template<class T>
void MySet<T>::delete_element(T el) {
	int i = -1;
	if (is_element(el)) i = MyVector<T>::find(el);
	else return;
	MyVector<T>::delete_element(i);
	MyVector<T>::sort();
}
template<class T>
void MySet<T>::add_element(T el) {
	for (int i = 0; i < MyVector<T>::Size(); i++) {
		if (MyVector<T>::pdata[i] == el) return;
	}
	MyVector<T>::add_element(el);
	MyVector<T>::sort();
}
template<class T>
bool MySet<T>::operator==(MySet<T>& s) {
	bool condition = 1;
	for (int i = 0; i < s.MyVector<T>::Size(); i++) {
		if (!this->is_element(s[i])) condition = 0;
	}
	return condition;
}
template<class T>
MySet<T>& MySet<T>::operator+=(MySet<T>& s) {
	*this = *this + s;
	return *this;
}
template<class T>
MySet<T>& MySet<T>::operator-=(MySet& s) {
	*this = *this - s;
	return *this;
}
template<class T>
MySet<T>& MySet<T>::operator*=(MySet& s) {
	*this = *this * s;
	return *this;
}
template<class T>
bool MySet<T>::is_element(T el) {
	int j = 0;
	if (MyVector<T>::find(el) > -1) j = 1;
	return j;
}
#endif
