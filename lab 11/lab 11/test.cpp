#include "pch.h"
#include <iostream>

int vector[10] = { 3,8,-1,10,-6,5 };
int expected[10] = { -6,-1,3,5,8,10 };
unsigned int nrElem = 6;

TEST(TestSortare, TestElementeSortate)
{
	sortare<int>(vector, nrElem);
	for (unsigned int i = 0; i < nrElem - 1; i++)
	{
		ASSERT_LE(vector[i], vector[i + 1]);
	}
}

TEST(TestSortare, TestElementeDuplicate)
{
	sortare<int>(vector, nrElem);
	for (unsigned int i = 0; i < nrElem - 1; i++)
	{
		int ok = 0;
		for (unsigned int j = 0; j < nrElem - 1; j++)
		{
			if (vector[i] == vector[j]) ok++;
		}
		EXPECT_EQ(ok, 1);
	}
}

TEST(TestSortare, TestVectorGol)
{
	sortare<int>(vector, nrElem);
	EXPECT_EQ(0, nrElem);
}

TEST(TestSortare, TestElementeSortateInvers)
{
	sortare<int>(vector, nrElem);
	for (unsigned int i = 0; i < nrElem - 1; i++)
	{
		ASSERT_GE(vector[i], vector[i + 1]);
	}
}
