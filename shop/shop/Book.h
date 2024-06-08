#pragma once
#include "Article.h"
#include <iostream>
#include <string>

using namespace std;

class Book :
	public Article
{
private:
	int pret, cantitate;
	string titlu, autor;
public:
	Book(int quantity, int price, string title, string author);
	string GetTitle();
	string GetAuthor();
	string GetType();
	int GetQuantity();
	int GetPrice();
	void Print();
};

