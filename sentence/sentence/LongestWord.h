#pragma once
#include "Procesor.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class LongestWord :
	public Procesor
{
private:
	string name;
public:
	LongestWord(string ceva);
	string GetName()override;
	int Compute(string ceva)override;
};

