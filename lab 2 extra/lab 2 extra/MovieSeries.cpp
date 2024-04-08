#include "MovieSeries.h"
#include <iostream>

using namespace std;

void MovieSeries::init()
{
	this->count = 0;
}

bool MovieSeries::add(Movie &film)
{
	if (this->count > 16)
		return 0;
	this->count++;
	movie[this->count] = film;
	return 1;
}

void MovieSeries::print()
{
	int i;
	for (i = 1; i <= count; i++)
	{
		cout << "Numele filmului este: %s\n" << movie[i].get_name();
		cout << "Durata filmului este: %d\n" << movie[i].get_lenght();
		cout << "Anul aparitiei filmului este: %d\n" << movie[i].get_year();
		cout << "Scorul filmului este: %f\n" << movie[i].get_score();
	}
}

void MovieSeries::sort()
{
	int i, j;
	for (i = 1; i < count; i++)
		for (j = i + 1; j <= count; j++)
			if ((movie[i].get_year() - movie[j].get_year()) > 0)
			{
				movie[count + 1] = movie[i];
				movie[i] = movie[j];
				movie[j] = movie[count + 1];
			}

}