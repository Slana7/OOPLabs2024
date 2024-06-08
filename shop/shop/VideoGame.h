#pragma once
#include "Article.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VideoGame :
	public Article
{
private:
	int pret, cantitate;
	string platforma, nume;
public:
	VideoGame(int price, int quantity, string platform, string name);
	string GetPlatform();
	string GetName();
	string GetType();
	int GetQuantity();
	int GetPrice();
	void Print();
};

