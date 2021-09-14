#include "Array.h"

ostream& table(ostream& stream)
{
	stream << '\t';
	return stream;
}

template<typename T> void Print(Array<T> ar);

int main()
{
	Array<int> ar(2);
	ar.Count(3);
	Print(ar);
}

template<typename T> void Print(Array<T> ar)
{
	for (int i = 0; i < ar.Length(); i++)
	{
		cout << "Array[" << i << "]" << table << ar[i] << endl;
	}
}