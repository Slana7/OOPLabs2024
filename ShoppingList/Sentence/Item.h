#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Item
{
private:
	string name;
public:
	string getName();
	virtual string getInfo() = 0;
	void setName(string nume);
};

