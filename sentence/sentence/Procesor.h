#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Procesor
{
public:
	virtual string GetName() = 0;
	virtual int Compute(string ceva) = 0;
};

