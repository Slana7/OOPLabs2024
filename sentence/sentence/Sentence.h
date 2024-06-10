#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Procesor.h"

using namespace std;

class Sentence
{
private:
	vector<Procesor*> procesators;
	string name;
public:
	Sentence(string ceva);
	void RunAll();
	void ListAll();
	void Run(string ceva);
	Sentence& operator+=(Procesor* ceva);
};

