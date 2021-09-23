#include <iostream>
#include "String.h"
#include <conio.h>

using namespace std;

int main()
{
	int n;
	cout << "Enter first string length: ";
	cin >> n;
	String a(n);
	cout << "Enter first string: ";
	cin >> a;
	cout << a << endl;
	cout << "Enter second string length: ";
	cin.clear();
	cin >> n;
	String b(n); 
	cout << "Enter second string: ";
	cin >> b;
	cout << b << endl;
	cout << "a - b: " << a - b << endl;
	a++;
	cout << "a++: " << a << endl;
	int i = a > b;
	cout << "a > b: " << i << endl;
}