#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int lines, int columns)
{
	int i, j;
	for (i = 0; i < lines; i++)
		for (j = 0; j < columns; j++)
			if ((i>=0 && i<width && j>=0 && j<height))
				canvas[i][j] = ' ';
}

void Canvas::print() const
{
	int i, j;
	for (i = 0; i < this->height; i++)
	{
		for (j = 0; j < this->width; j++)
			cout << canvas[i][j] << ' ';
		cout << endl;
	}
}