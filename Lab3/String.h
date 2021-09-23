#pragma once
#include<iostream>

using namespace std;

class String
{
public:
	String();
	String(int sz);
	String(const String& str);
	~String();

	int Size();
	int Length();

	char& operator[](int i);
	int operator-(const String a);
	int operator>(const String a);
	String& operator++();
	String operator++(int);
	friend ostream& operator<<(ostream& os, String& st);
	friend istream& operator>>(istream& os, String& st);
private:
	char* str = nullptr;
	int size;
};

