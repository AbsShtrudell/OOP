#pragma once

template<class T> class Array
{
public:
	Array<T>()
	{}
	~Array();

private:
	T* values;
};

