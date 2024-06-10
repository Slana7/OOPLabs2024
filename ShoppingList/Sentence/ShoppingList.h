#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class ShoppingList
{
private:
	vector<Item*> items;
public:
	void addItem(Item* ceva);
	void printList();
};

