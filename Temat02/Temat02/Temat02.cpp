// Temat02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

double delta(double a, double b, double c)
{
	return b*b - 4 * a*c;
}

int main()
{
	double a, b, c;
	do
	{
		printf("Podaj wspolczynnik a rozny od zera\n");
		cin>>a;
	}
	while (!a);
	printf("Podaj wspolczynnik b\n");
	cin>>b;
	printf("Podaj wspolczynnik c\n");
	cin>>c;
	if (delta(a, b, c) > 0)
	{
		double x1 = (-1 * b - sqrt(delta(a, b, c)) / (2 * a));
		double x2 = (-1 * b + sqrt(delta(a, b, c)) / (2 * a));
		
	}
	else if (delta(a, b, c) < 0)
	{
		printf("Rownanie nie ma pierwiastkow\n");
	}
	else
	{
		double x0 = -b / 2 * a;
		printf("Rownanie ma jeden pierwiastek rowny %fl\n", x0);
	}
	system("pause");
    return 0;
}

