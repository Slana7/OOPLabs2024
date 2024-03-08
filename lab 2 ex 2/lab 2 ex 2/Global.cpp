#include "Global.h"
#include <iostream>
#include <cstring>

using namespace std;

int CompNume(Students* a, Students* b)
{
	char* nume1 = a->GetName();
	char* nume2 = b->GetName();
	if (strcmp(nume1, nume2) == 0)
		return 0;
	else if (strcmp(nume1, nume2) > 0)
		return 1;
	else
		return -1;
}

int CompNotaMate(Students* a, Students* b)
{
	float nota1 = a->GetNotaMate();
	float nota2 = b->GetNotaMate();
	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else
		return -1;
}

int CompNotaEng(Students* a, Students* b)
{
	float nota1 = a->GetNotaEng();
	float nota2 = b->GetNotaEng();
	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else
		return -1;
}

int CompNotaIst(Students* a, Students* b)
{
	float nota1 = a->GetNotaIst();
	float nota2 = b->GetNotaIst();
	if (nota1 == nota2)
		return 0;
	else if (nota1 > nota2)
		return 1;
	else
		return -1;
}

int CompMedie(Students* a, Students* b)
{
	float media1 = a->Media();
	float media2 = b->Media();
	if (media1 == media2)
		return 0;
	else if (media1 > media2)
		return 1;
	else
		return -1;
}