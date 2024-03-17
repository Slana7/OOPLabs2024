#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	int nr = 5;
	NumberList m;
	m.Init();
	if (m.Add(nr) == 0)
	{
		cout << "vectorul e plin deja";
	}
	m.Sort();
	m.Print();
	return 0;
}