// l14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include"Interface.h"
#include"Algoritm.h"


using namespace std;


int main()
{
	Algoritm alg;
	string mainstr = "asd ss saa 3  asdasd asdasd asdasdasd asdasd";

	

	cout << "Count words: "<< alg.GetCountWords(mainstr, 5) << endl;
	system("pause");
    return 0;
}

