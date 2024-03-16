#include "Math.h"
#include <cmath>
#include <algorithm>

using namespace std;

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return (int)(a + b);
}

int Math::Add(double a, double b, double c)
{
	return (int)(a + b + c);
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return (int)(a * b);
}

int Math::Mul(double a, double b, double c)
{
	return (int)(a * b * c);
}

int Math::Add(int count, ...)
{
	va_list vl;
	va_start(vl, count);
	int suma = 0, i;
	for (i = 0; i < count; i++)
	{
		suma += va_arg(vl, int);
	}
	va_end(vl);
	return suma;
}

char* Math::Add(const char* firstNum, const char* secondNum)
{
    int maxLength = 0, sum, i, carry = 0;
    if (strlen(firstNum) > strlen(secondNum))
        maxLength = strlen(firstNum);
    else
        maxLength = strlen(secondNum);
    char* result = new char[maxLength + 1] {};
    strcpy(result, " ");
    int indexFirstNum = strlen(firstNum) - 1;
    int indexSecondNum = strlen(secondNum) - 1;
    for (maxLength; maxLength > 0; maxLength--)
    {
        sum = 0;
        if (indexFirstNum >= 0)
        {
            sum = sum + firstNum[indexFirstNum] - '0';
            indexFirstNum--;
        }
        if (indexSecondNum >= 0)
        {
            sum = sum + secondNum[indexSecondNum] - '0';
            indexSecondNum--;
        }
        if (carry == 1)
            sum++;
        if (sum / 10 != 0)
            carry = 1;
        else
            carry = 0;
        result[maxLength] = sum % 10 + '0';
    }
    if (strlen(firstNum) > strlen(secondNum))
        maxLength = strlen(firstNum);
    else
        maxLength = strlen(secondNum);
    if (carry == 1)
    {
        maxLength++;
        result[0] = '1';
        result[maxLength] = '\0';
    }
    else
    {
        for (i = 0; i < maxLength; i++)
            result[i] = result[i + 1];
        result[maxLength] = '\0';
    }
    return result;
    delete[] result;

}