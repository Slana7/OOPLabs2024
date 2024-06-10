#pragma once
#include "Procesor.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ComputeVowals :
	public Procesor
{
private:
	string nume;
public:
	ComputeVowals(string ceva);
	string GetName()override;
	int Compute(string ceva)override;
};

