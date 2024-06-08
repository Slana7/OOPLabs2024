#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Article.h"

using namespace std;

class Shop
{
private:
	vector<Article*> items;
public:
	Shop& Add(Article* ceva);
	int GetTotalPrice();
	int GetQuantity(string);
	void List();
};

