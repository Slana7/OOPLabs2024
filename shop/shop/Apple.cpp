#include "Apple.h"
#include <string>
#include <iostream>

using namespace std;

Apple::Apple(int price, int quantity, string origin)
{
	this->pret = price;
	this->cantitate = quantity;
	this->origine = origin;
}
string Apple::GetOrigin() 
{
	return this->origine;
}
string Apple::GetType() 
{
	return "Apple";
}
int Apple::GetQuantity() 
{
	return this->cantitate;
}
int Apple::GetPrice() 
{
	return this->pret;
}
void Apple::Print() 
{
	cout << this->GetType() << "(from=" << this->GetOrigin() << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << '\n';
}