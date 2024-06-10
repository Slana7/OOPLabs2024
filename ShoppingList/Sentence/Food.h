#pragma once
#include "Item.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Food :
	public Item
{
private:
	float quantity;
public:
	void setQuantity(float cantitate);
	string getInfo() override;
};

