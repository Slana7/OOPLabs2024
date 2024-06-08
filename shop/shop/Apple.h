#pragma once
#include "Article.h"
#include <iostream>
#include <string>

using namespace std;

class Apple :
	public Article
{
private:
	int pret, cantitate;
	string origine;
public:
	Apple(int price, int quantity, string origin);
	string GetOrigin();
	string GetType();
	int GetQuantity();
	int GetPrice();
	void Print();
};

