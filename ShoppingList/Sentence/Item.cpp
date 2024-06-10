#include "Item.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string Item::getName()
{
	return this->name;
}

void Item::setName(string nume)
{
	this->name = nume;
}