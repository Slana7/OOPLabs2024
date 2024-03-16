#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include<iostream>

using namespace std;

Math functie;

int main()
{
	int a = 5, b = 4, c = 12;
	double ad = 0.5, bd = 10.0, cd = 3.0;
	char s1[] = "123", s2[] = "321";
	cout << functie.Add(a, b) << endl;
	cout << functie.Add(a, b, c) << endl;
	cout << functie.Add(ad, bd) << endl;
	cout << functie.Add(ad, bd, cd) << endl;
	cout << functie.Mul(a, b) << endl;
	cout << functie.Mul(a, b, c) << endl;
	cout << functie.Mul(ad, bd) << endl;
	cout << functie.Mul(ad, bd, cd) << endl;
	cout << functie.Add(4, a, b, c, 7) << endl;
	cout << functie.Add(s1, s2) << endl;
}