//
// pch.h
//

#pragma once

#include "gtest/gtest.h"


template<class T>
void sortare_corecta(T* elemente, unsigned int nrElem) { // sortare corecta
    for (unsigned int i = 0; i < nrElem - 1; ++i) {
        for (unsigned int j = 0; j < nrElem - i - 1; ++j) {
            if (elemente[j] > elemente[j + 1]) {
                T temp = elemente[j];
                elemente[j] = elemente[j + 1];
                elemente[j + 1] = temp;
            }
        }
    }
}


template<class T>
void sortare(T* elemente, unsigned int nrElem) { // sortare gresita
    for (unsigned int i = 0; i < nrElem - 1; ++i) {
        for (unsigned int j = 0; j < nrElem - i - 2; ++j) { // greseala e -2 in loc de -1
            if (elemente[j] > elemente[j + 1]) {
                T temp = elemente[j];
                elemente[j] = elemente[i + 1];
                elemente[j - 1] = temp; // greseala e -1 in loc de + 1
            }
        }
    }
}
