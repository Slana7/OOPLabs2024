#include "Sort.h"
#include <iostream>

using namespace std;

Sort::Sort(int countelem, int min, int max)
{
    srand(time(NULL));
    this->length = countelem;
    this->arr = new int[countelem];
    for (int i = 0; i < this->length; i++)
        this->arr[i] = rand() % (max - min) + min;
}

void Sort::InsertSort(bool ascendent = false) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = elements[i];
        int j = i - 1;

        // Move elements of elements[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && ((!ascendent && elements[j] > key) || (ascendent && elements[j] < key))) {
            elements[j + 1] = elements[j];
            j = j - 1;
        }
        elements[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent = false)
{
	if (st < dr)
	{
		//pivotul este inițial v[st]
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st, i - 1);
		QuickSort(v, i + 1, dr);
	}
}

void Sort::BubbleSort(bool ascendent = false)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void Sort::Print()
{
    for (int i = 0; i < this->length; i++)
    {
        cout << arr[i] << ' ';
    }
}

int Sort::GetElementsCount()
{
    return this->length;
}