// CodeBuilderExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CodeBuilder.h"

using namespace std;

int main()
{
	auto cb = CodeBuilder{ "Person" }.add_field("name", "string").add_field("age", "int");
	cout << cb;

	getchar();
}

