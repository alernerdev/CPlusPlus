// Iterations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
	int a[]{ 1,2,3,4 };

	for (int i = 0; i < 4; i++)
		cout << a[i] << '\t';

	cout << endl;

	// increment by number of "units" in the array
	for (int *p = a, *e = a + 4; p != e; ++p)
		cout << *p << '\t';
	cout << endl;

	auto ba = begin(a);
	auto ea = end(a);
	for (; ba != ea; ba++)
		cout << *ba << '\t';
	cout << endl;

	for (auto value : a)
		cout << value << '\t';
	cout << endl;

	vector<int> v{ 5,6,7,8 };
	auto bv = v.begin();
	auto cbv = v.cbegin(); // constant iterator

	// reverse begin
	for (auto i = v.rbegin(); i != v.rend(); ++i)
		cout << *i << '\t';
	cout << endl;

	getchar();
	return 0;
}
