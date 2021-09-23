#include "String.h"

String::String()
{
	size = 2;
	str = new char[size];
	memset(str, 0, size * sizeof(char));
	str[0] = '1';
	str[1] = '\0';
}

String::String(int sz)
{
	this->size = sz;
	str = new char[size];
	memset(str, 0, size * sizeof(char));
	str[0] = '\0';
}

String::String(const String& str)
{
	size = str.size;
	this->str = new char[size];
	memcpy_s(this->str, size * sizeof(char), str.str, str.size * sizeof(char));
}

String::~String()
{
	delete[]str;
}

int String::Size()
{
	return size;
}

int String::Length()
{
	int i = 0;
	for (; str[i] != '\0'; i++)
	{}

	return i + 1;
}

char& String::operator[](int i)
{
	{
		return *(str + i);
	}
}

int String::operator-(String a)
{
	return this->Length() - a.Length() >= 0 ? this->Length() - a.Length() : a.Length() - this->Length();
}

int String::operator>(const String a)
{
	int i = 0;
	while (this->str[i] != '\0' || a.str[i] != '\0')
	{
		if (this->str[i] != a.str[i])
			return (unsigned int)this->str[i] - (unsigned int)a.str[i];
		i++;
	}
	return 0;
}

String& String::operator++()
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		this->str[i] = str[i] + 1;
		i++;
	}
	return *this;
}

String String::operator++(int)
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		this->str[i] = str[i] + 1;
		i++;
	}
	return *this;
}

ostream& operator<<(std::ostream& os, String&  st)
{
	for(int i = 0; st[i] != '\0'; i++)
	{
		os << st[i];
	}
	return os;
}

istream& operator>>(istream& os, String& st)
{
	memset(st.str, 0, st.size * sizeof(char));
	os.clear();
	os.ignore(1, '\n');
	os.getline(st.str, st.Size(), '\0');
	return os;
}
