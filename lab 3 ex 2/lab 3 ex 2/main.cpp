#define _CRT_SECURE_NO_WARNINGS
#include "Canvas.h"
#include<iostream>


int main()
{
	Canvas Matrice(120, 30);

	Matrice.Clear();
	Matrice.DrawCircle(5, 5, 2, 'm');
	Matrice.Print();
	return 0;
}