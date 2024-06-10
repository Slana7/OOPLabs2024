#include "ShoppingList.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void ShoppingList::addItem(Item* ceva)
{
	items.push_back(ceva);
}

void ShoppingList::printList()
{
	for (auto i : items)
	{
		cout << i->getName() << " : " << i->getInfo() << ";";
	}
}