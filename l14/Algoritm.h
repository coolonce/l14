#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;
class Algoritm
{
public:
	Algoritm();
	~Algoritm();
	size_t GetCountWords(string str, int countChar);
	vector<string> SplitQuery(string str);
};

