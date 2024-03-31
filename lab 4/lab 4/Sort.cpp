#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdarg.h>

using namespace std;

Sort::Sort(int n, int mini, int maxi)
{
	int i;
	v = new int[n];
	srand(time(0));
	this->count = n;
	for (i = 0; i < n; i++)
		this->v[i] = (rand() % (maxi - mini) + 1) + mini;
}

Sort::Sort() : v(new int[6]{ 1, 2, 3, 4, 5, 6 })
{
	this->count = 6;
}

Sort::Sort(int a[10001], int nr)
{
	int i;
	v = new int[nr];
	this->count = nr;
	for (i = 0; i < nr; i++)
		this->v[i] = a[i];
}

Sort::Sort(int cntparam...)
{
	v = new int[cntparam];
	va_list vl;
	this->count = cntparam;
	va_start(vl, cntparam);
	for (int i = 0; i < cntparam; i++)
	{
		this->v[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(char* s)
{
	v = new int[strlen(s)];
	this->count = 0;
	char* p;
	int nr, pow, i;
	p = strtok(s, ",");
	while (p)
	{
		this->count++;
		nr = 0;
		pow = 1;
		for (i = strlen(p) - 1; i >= 0; i--)
		{
			nr = nr + pow * (p[i] - '0');
			pow = pow * 10;
		}
		this->v[this->count - 1] = nr;
		p = strtok(NULL, ",");
	}
}

void  Sort::InsertSort(bool ascendent)
{
	int i, elem, j;
	if (ascendent == true)
		for (i = 1; i < this->count; i++)
		{
			elem = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] > elem)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = elem;
		}
	else
		for (i = 1; i < this->count; i++)
		{
			elem = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] < elem)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = elem;
		}
}

int partition(int v[], bool ascendent, int left, int right)
{
	int pivot = v[right], i = (left - 1);
	for (int j = left; j <= right; j++)
	{
		if (ascendent == true)
		{
			if (v[j] < pivot)
			{
				i++;
				swap(v[i], v[j]);
			}
		}
		else
			if (v[j] > pivot)
			{
				i++;
				swap(v[i], v[j]);
			}
	}
	swap(v[i + 1], v[right]);
	return (i + 1);
}

void quickSort(int v[], bool ascendent, int left, int right)
{
	int pivot;
	if (left < right)
	{
		pivot = partition(v, ascendent, left, right);
		quickSort(v, ascendent, left, pivot - 1);
		quickSort(v, ascendent, pivot + 1, right);
	}
}

void  Sort::QuickSort(bool ascendent)
{
	quickSort(v, ascendent, 0, this->count - 1);
}

void  Sort::BubbleSort(bool ascendent)
{
	int i, j, aux;
	bool ok;
	if (ascendent == true)
		for (i = 0; i < this->count - 1; i++)
		{
			ok = false;
			for (j = 0; j < this->count - i - 1; j++)
				if (this->v[j] > this->v[j + 1])
				{
					swap(this->v[j], this->v[j + 1]);
					ok = true;
				}
			if (ok == false)
				break;
		}
	else
		for (i = 0; i < this->count - 1; i++)
		{
			ok = false;
			for (j = 0; j < this->count - i - 1; j++)
				if (this->v[j] < this->v[j + 1])
				{
					swap(this->v[j], this->v[j + 1]);
					ok = true;
				}
			if (ok == false)
				break;
		}
}

void  Sort::Print()
{
	int i;
	for (i = 0; i < this->count; i++)
		cout << this->v[i] << ' ';
	cout << endl;
}

int Sort::GetElementsCount()
{
	return this->count;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= this->count)
	{
		cout << "prea putine elem";
		return 0;
	}
	return this->v[index];
}