#pragma once
#include "Item.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Miscellaneous :
	public Item
{
private:
	int count;
public:
	string getInfo() override;
	void setCount(int nr);
};

