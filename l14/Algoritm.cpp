#include "stdafx.h"
#include "Algoritm.h"

using namespace std;
Algoritm::Algoritm()
{
}


Algoritm::~Algoritm()
{
}


size_t Algoritm::GetCountWords(string str, int countChar)
{
	vector<string> words;
	string delim(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	while ((next = str.find(delim, prev)) != string::npos) {
		string tmp = str.substr(prev, next - prev);
		if(tmp.size() < countChar)
		{ 
			words.push_back(tmp);
		}		
		prev = next + delta;
	}
	return words.size();
}

vector<string> Algoritm::SplitQuery(string str)
{
	vector<string> words;
	string delim(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	while ((next = str.find(delim, prev)) != string::npos) {
		string tmp = str.substr(prev, next - prev);
		words.push_back(tmp);
		prev = next + delta;
	}
	return words;
}


