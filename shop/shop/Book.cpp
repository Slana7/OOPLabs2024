#include "Book.h"

Book::Book(int price, int quantity, string title, string author)
{
	this->cantitate = quantity;
	this->pret = price;
	this->titlu = title;
	this->autor = author;
}
string Book::GetTitle()
{
	return this->titlu;
}
string Book::GetAuthor()
{
	return this->autor;
}
string Book::GetType()
{
	return "Book";
}
int Book::GetQuantity()
{
	return this->cantitate;
}
int Book::GetPrice()
{
	return this->pret;
}
void Book::Print()
{
	cout << this->GetType() << "(Title=" << this->GetTitle() << ", Author=" << this->GetAuthor() << ") Price=" << this->GetPrice() << " Quantity=" << this->GetQuantity() << '\n';
}