#include "Students.h"
#include <cstring>
#include <iostream>

using namespace std;

void Students::SetName(char* numestudent)
{
	int i;
	for (i = 0; i < 256; i++)
	{
		this->nume[i] = numestudent[i];
	}
}

char* Students::GetName()
{
	return nume;
}

void Students::SetNotaMate(float nota)
{
	this->notamate = nota;
}

float Students::GetNotaMate()
{
	return notamate;
}

void Students::SetNotaEng(float nota)
{
	this->notaeng = nota;
}

float Students::GetNotaEng()
{
	return notaeng;
}

void Students::SetNotaIst(float nota)
{
	this->notaist = nota;
}

float Students::GetNotaIst()
{
	return notaist;
}

float Students::Media()
{
	return (notamate + notaeng + notaist) / 3;
}