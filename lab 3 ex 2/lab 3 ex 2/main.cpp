#define _CRT_SECURE_NO_WARNINGS
#include "Canvas.h"
#include<iostream>


int main()
{
	Canvas Matrice(120, 30);

	Matrice.Clear();
	//Matrice.DrawRect(0, 0, 4, 4, 'o');
	//Matrice.FillRect(0, 0, 4, 4, 'o');
	//Matrice.DrawCircle(10, 10, 2, 'C');
	//Matrice.FillCircle(10, 10, 4, 'C');
	Matrice.DrawLine(1, 1, 6, 10, 'm');
	Matrice.Print();
	return 0;
}