#include "Food.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void Food::setQuantity(float cantitate)
{
	this->quantity = cantitate;
}

string Food::getInfo()
{
	return to_string(quantity)+"kg";
}