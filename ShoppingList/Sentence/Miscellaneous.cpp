#include "Miscellaneous.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string Miscellaneous::getInfo()
{
	return to_string(count) + " items";
}

void Miscellaneous::setCount(int nr)
{
	this->count = nr;
}
