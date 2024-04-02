#include "Number.h"
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

Number::Number(const char* value, int base)
{
	this->base = base;
	int i, j;
	for (i = 0; value[i] != '\0'; i++);
	this->digits = new char[i] {};
	if (base <= 16 && base > 0)
		for (j = i; j >= 0; j--)
			this->digits[i] = value[i];
	this->digits[i] = '\0';
}

Number::Number(const Number& other)
{
	this->digits = new char[sizeof(other.digits)];
	this->base = other.base;
	this->digits = other.digits;
}

Number::Number(Number&& other)
{
	this->base = other.base;
	this->digits = new char[sizeof(other.digits)];
	char* copy = other.digits;
	other.digits = nullptr;
	this->digits = copy;
}

Number::Number(int value)
{
	this->base = 10;
	int power = 1, log = 0, index, i;
	while (value >= power)
	{
		power = power * this->base;
		log++;
	}
	index = log;
	this->digits = new char[index];
	for (i = 0; i < index; i++) {};
	this->digits[index] = '\0';
	for (i = index - 1; i >= 0; i--)
	{
		if (value % this->base < 10)
			this->digits[i] = (value % this->base) + '0';
		else
			this->digits[i] = (value % this->base) - 10 + 'A';
		value = value / this->base;
	}
}

Number::~Number()
{
	delete[] digits;
}

Number operator+(Number a, Number b)
{
	int powera = 1, powerb = 1, abase = 0, bbase = 0, bazamax, i, index, putere=1, log=0;
	for (i = a.GetDigitsCount() - 1; i >= 0; i--)
	{
		bbase = powerb * (a.digits[i] - '0') + bbase;
		powerb = powerb * a.base;
	}
	for (i = b.GetDigitsCount() - 1; i >= 0; i--)
	{
		abase = powera * (b.digits[i] - '0') + abase;
		powera = powera * b.base;
	}
	abase += bbase;
	bazamax = a.base;
	if (b.base > bazamax)
		bazamax = b.base;
	putere = 1;
	log = 0;
	while (abase >= putere)
	{
		putere = putere * bazamax;
		log++;
	}
	index = log;
	Number rez("0", 10);
	rez.digits = new char[log] {};
	rez.base = bazamax;
	for (i = 0; i <= log; i++)
		rez.digits[i] = ' ';
	rez.digits[log + 1] = '\0';
	for (i = index - 1; i >= 0; i--)
	{
		if (abase % bazamax < 10)
			rez.digits[i] = (abase % bazamax) + '0';
		else
			rez.digits[i] = (abase % bazamax) - 10 + 'A';
		abase = abase / bazamax;
	}
	return rez;
}

Number operator-(Number a, Number b)
{
	int powera = 1, powerb = 1, abase = 0, bbase = 0, bazamax, i, index, putere = 1, log = 0;
	for (i = a.GetDigitsCount() - 1; i >= 0; i--)
	{
		bbase = powerb * (a.digits[i] - '0') + bbase;
		powerb = powerb * a.base;
	}
	for (i = b.GetDigitsCount() - 1; i >= 0; i--)
	{
		abase = powera * (b.digits[i] - '0') + abase;
		powera = powera * b.base;
	}
	bbase -= abase;
	bazamax = a.base;
	if (b.base > bazamax)
		bazamax = b.base;
	while (bbase >= putere)
	{
		putere = putere * bazamax;
		log++;
	}
	index = log;
	Number rez("0", 10);
	rez.digits = new char[log] {};
	rez.base = bazamax;
	for (i = 0; i <= log; i++)
		rez.digits[i] = ' ';
	rez.digits[log + 1] = '\0';
	for (i = index - 1; i >= 0; i--)
	{
		if (bbase % bazamax < 10)
			rez.digits[i] = (bbase % bazamax) + '0';
		else
			rez.digits[i] = (bbase % bazamax) - 10 + 'A';
		bbase = bbase / bazamax;
	}
	return rez;
}

Number Number::operator= (Number n1)
{
	this->digits = n1.digits;
	this->base = n1.base;
	return (*this);
}

Number& Number::operator--()
{
	this->digits[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}

Number Number::operator--(int)
{
	int i;
	for (i = 0; i < this->GetDigitsCount(); i++)
		this->digits[i] = this->digits[i + 1];
	this->digits[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}

char Number::operator[](int i)
{
	return digits[i];
}

bool Number::operator==(Number& other)
{
	int i;
	if (size != other.size || base != other.base)
		return false;
	for (i = 0; i < size; i++)
	{
		if (digits[i] != other.digits[i])
		{
			return false;
		}
	}
	return true;
}

bool Number::operator!=(Number& other)
{
	return !(*this == other);
}

bool Number::operator>(Number& other)
{
	if (size > other.size)
		return true;
	else if (size < other.size)
		return false;
	else
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (digits[i] > other.digits[i])
				return true;
			else if (digits[i] < other.digits[i])
				return false;
		}
		return false;
	}
}

bool Number::operator<(Number& other)
{
	return other > *this;
}

bool Number::operator>=(Number& other)
{
	return !(*this < other);
}

bool Number::operator<=(Number& other)
{
	return !(other < *this);
}

void Number::SwitchBase(int newBase)
{
	int oldBase = base, i, power = 1, decValue = 0, digit;
	if (newBase == oldBase)
		return;
	for (i = size - 1; i >= 0; i--)
	{
		digit = (digits[i] >= 'A') ? (digits[i] - 'A' + 10) : (digits[i] - '0');
		decValue += digit * power;
		power *= oldBase;
	}
	i = 0;
	while (decValue > 0)
	{
		digit = decValue % newBase;
		if (digit >= 10)
			digits[i] = 'A' + (digit - 10);
		else
			digits[i] = '0' + digit;
		i++;
		decValue /= newBase;
	}
	size = i;
	base = newBase;
	digits[i] = '\0';
	reverse(digits, digits + size);
}

void Number::Print()
{
	cout << this->digits <<endl;
}

int Number::GetDigitsCount()
{
	int i;
	for (i = 0; this->digits[i] != '\0'; i++);
	return i;
}

int Number::GetBase()
{
	return this->base;
}
