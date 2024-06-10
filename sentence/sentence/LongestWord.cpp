#include "LongestWord.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

LongestWord::LongestWord(string ceva)
{
	this->name = ceva;
}

string LongestWord::GetName()
{
	return this->name;
}

int LongestWord::Compute(string ceva)
{
	int lgmax = 0, lg = 0;
	for (auto i : ceva)
	{
		if (i != ' ')
		{
			lg++;
		}
		else
		{
			if (lg > lgmax)
			{
				lgmax = lg;
			}
			lg = 0;
		}
	}
	if (lg > lgmax)
	{
		lgmax = lg;
	}
	return lgmax;
}