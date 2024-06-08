#include "VideoGame.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

VideoGame::VideoGame(int price, int quantity, string platform, string name)
{
	this->pret = price;
	this->cantitate = quantity;
	this->platforma = platform;
	this->nume = name;
}
string VideoGame::GetPlatform()
{
	return this->platforma;
}
string VideoGame::GetName()
{
	return this->nume;
}
string VideoGame::GetType()
{
	return "VideoGame";
}
int VideoGame::GetQuantity()
{
	return this->cantitate;
}
int VideoGame::GetPrice()
{
	return this->pret;
}
void VideoGame::Print()
{
	cout << this->GetType() << " (Platform=" << this->GetPlatform() << ", Name=" << this->GetName() << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << '\n';
}
