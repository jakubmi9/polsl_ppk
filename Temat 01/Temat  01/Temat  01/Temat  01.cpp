// Temat  01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int delta(int a, int b, int c)
{
	return (b*b) - 4 * (a*c);
}

int main()
{
	int a, b, c,x1, x2;
	scanf_s("%d %d %d", &a, &b, &c);
	if (a == 0)
	{
		printf("Rownanie nie jest kwadratowe\n");
		//...
		if (b == 0)
		{
			printf("Rownanie nie ma rozwiazan\n");
			system("pause");
			return 0;
		}
		printf("Rownanie ma jedno rozwiazanie\nx = %d\n", ((-1 * c) / (b)));
		system("pause");
		return 0;
	}
	if (b == 0)
	{
		printf("Rownanie nie ma rozwiazan\n");
		system("pause");
		return 0;
	}
	if (delta(a, b, c) < 0)
	{
		printf("Rownanie nie ma rozwiazan\n");
		system("pause");
		return 0;
	}
	if (delta(a, b, c) == 0)
	{
		printf("Rownanie ma jedno rozwiazanie\nx = %d\n", ((-1*b) / (2 * a)));
		system("pause");
		return 0;
	}
	if (a != 0)
	{
		x1 = -1 * b - sqrt(delta(a, b, c)) / 2 * a;
		x2 = -1 * b + sqrt(delta(a, b, c)) / 2 * a;
		printf("Rownanie ma 2 rozwiazania\nx1 = %d, a x2 = %d\n", x1, x2);
		system("pause");
	}
	printf("!\n");
	system("pause");
    return 0;
}

