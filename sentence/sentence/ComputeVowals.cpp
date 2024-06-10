#include "ComputeVowals.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

ComputeVowals::ComputeVowals(string ceva)
{
	this->nume = ceva;
}

string ComputeVowals::GetName()
{
	return this->nume;
}

int ComputeVowals::Compute(string ceva)
{
	int cnt = 0;
	for (auto i : ceva)
	{
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
		{
			cnt++;
		}
	}
	return cnt;
}