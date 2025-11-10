#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

class Validation
{
public:
	static string name_validation(string name);
	static string password_validation(string password);
	static double salary_validation(double salary);
	static double balance_validation(double balance);
};

