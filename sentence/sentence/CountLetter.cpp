#include "CountLetter.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

CountLetter::CountLetter(string ceva, bool (*verif)(char))
{
	this->name = ceva;
	this->fnc = verif;
}

string CountLetter::GetName()
{
	return this->name;
}

int CountLetter::Compute(string ceva)
{
	int cnt = 0;
	for (auto i : ceva)
	{
		if (fnc(i))
			cnt++;
	}
	return cnt;
}