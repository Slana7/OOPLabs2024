#include "NumberList.h"
#include <iostream>

using namespace std;


void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
        if (this->count >= 10)
        {
            return false;
        }
        this->numbers[this->count++] = x;
        return true;
}

void NumberList::Sort()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (this->numbers[i] > this->numbers[i + 1])
            swap(this->numbers[i], this->numbers[i + 1]);
    }
}

void NumberList::Print()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%i", this->numbers[i]);
    }
}