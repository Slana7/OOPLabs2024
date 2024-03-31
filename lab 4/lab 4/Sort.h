#pragma once
class Sort
{
    // add data members
    int length;
    int* arr;
public:
    // add constuctors
    Sort(int countelem, int min, int max);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();    
    int  GetElementFromIndex(int index);
}

