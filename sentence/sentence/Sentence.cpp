#include "Sentence.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Sentence::Sentence(string ceva)
{
	this->name = ceva;
}

void Sentence::RunAll()
{
	for (auto i : procesators)
	{
		cout << "Name:" << i->GetName() << " => " << i->Compute(this->name) << endl;
	}
}

void Sentence::ListAll()
{
	for (auto i : procesators)
	{
		cout << "Name:" << i->GetName() << endl;
	}
}

void Sentence::Run(string ceva)
{
	for (auto i : procesators)
	{
		if (i->GetName() == ceva)
		{
			cout << i->Compute(this->name);
		}
	}
}

Sentence& Sentence::operator+=(Procesor* ceva)
{
	procesators.push_back(ceva);
	return *this;
}