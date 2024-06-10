#pragma once
#include "Procesor.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CountLetter :
	public Procesor
{
private:
	string name;
	bool (*fnc)(char);
public:
	CountLetter(string ceva, bool (*verif)(char));
	string GetName()override;
	int Compute(string ceva)override;
};

