#pragma once
class Number
{
private:
	char* digits;
	int base = 10, size = 0;
public:
	Number(const char* value, int base);
	Number(const Number& other);
	Number(Number&& other);
	Number(int value);
	~Number();

	friend Number operator+(Number a, Number b);
	friend Number operator-(Number a, Number b);
	Number operator= (Number n1);
	Number& operator--();
	Number operator--(int val);
	char operator[](int val);
	bool operator==(Number& other);
	bool operator!=(Number& other);
	bool operator>(Number& other);
	bool operator<(Number& other);
	bool operator>=(Number& other);
	bool operator<=(Number& other);

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();

};
