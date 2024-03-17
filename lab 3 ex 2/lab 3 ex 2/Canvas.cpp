#include "Canvas.h"
#include <iostream>
#include <algorithm>

using namespace std;

Canvas::Canvas(int w, int h)
{
	int i, j;
	canvas = new char*[this->height];
	for (i = 0; i < this->height; ++i)
	{
		canvas[i] = new char[this->width];
		for (j = 0; j < this->width; ++j)
		{
			canvas[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int i, j;
	if (x < this->height && y < this->width)
	{
		for (i = 0; i < this->height; i++)
		{
			for (j = 0; j < this->width; j++)
			{
				if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
					canvas[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int i, j;
	if (x < this->height && y < this->width)
	{
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				if ((i - x) * (i - x) + (j - y) * (j - y) < ray * ray - 15)
					canvas[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < this->width && top < this->height && right < this->width && bottom < this->height)
	{
		for (int i = left; i <= right; i++)

		{
			canvas[top][i] = ch;
			canvas[top][i] = ch;
		}
		for (int i = top; i <= bottom; i++)
		{
			canvas[i][left] = ch;
			canvas[i][right] = ch;
		}

	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	if (left < this->width && top < this->height && right < this->width && bottom < this->height)
	{
		for (i = top; i <= bottom; i++)
			for (j = left; j <= right; j++)
				canvas[i][j] = ch;
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x <= width && y >= 0 && y <= height)
		canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1, dy=y2-y2, xi=1;
	if (dx < 0)
	{
		dx = -dx;
		xi = -1;
	}
	int D = (2 * dx) - dy;
	int x = x1;
	for (int y = y1; y <= y2; y++)
	{
		canvas[x][y] = ch;
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else
		{
			D = D + 2 * dx;
		}
	}
}

void Canvas::Print()
{
	int i, j;
	for (i = 0; i < this->height; i++)
	{
		for (j = 0; j < this->width; j++)
			cout << canvas[i][j] << ' ';
		cout << endl;
	}
}

void Canvas::Clear()
{
	int i, j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			canvas[i][j] = ' ';
}