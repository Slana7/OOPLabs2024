#include "Shop.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Shop& Shop::Add(Article* ceva)
{
	items.push_back(ceva);
	return *this;
}

int Shop::GetTotalPrice()
{
	int s = 0;
	for (auto i : items)
	{
		s = s + (i->GetPrice()*i->GetQuantity());
	}
	return s;
}

int Shop::GetQuantity(string type)
{
	int cnt = 0;
	for (auto i : items)
	{
		if (type == i->GetType())
			cnt=cnt+i->GetQuantity();
	}
	return cnt;
}

void Shop::List()
{
	for (auto i : items)
	{
		i->Print();
	}
}