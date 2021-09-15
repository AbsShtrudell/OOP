#pragma once
#include<iostream>

using namespace std;

template<typename T> class Array
{
public:
	Array(int sz): size(sz)
	{
		array = new T[size];
		memset(array, 0, size * sizeof(T));
	}

	Array(const Array& arr) {
		size = arr.size;
		array = new T[size];
		memcpy_s(array, size * sizeof(T), arr.array, arr.size * sizeof(T));
	}
	
	~Array()
	{
		delete[]array;
	}

	T& operator[](int i) 
	{
		return *(array + i);
	}

	int Length()
	{
		return size;
	}
	
	T Count(T n)
	{
		T step = 1 - (T)0.5;
		T sum = 0;
		for (T i = 1; i <= n; i += step)
			sum += i;
		return sum;
	}

private:
	T* array;
	int size;
};