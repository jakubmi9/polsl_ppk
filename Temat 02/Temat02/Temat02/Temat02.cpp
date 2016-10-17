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
	srand(time(0));
	const int tabsize = 100;
	int tab[tabsize];
	for(int i =0;i<tabsize;i++)
	{
		tab[i] = rand();
	}
	int i = 0;
	int szukana;
	cin >> szukana;
	bool fuse = 1;
	while (fuse && i < tabsize)
	{
		if (tab[i] == szukana)
		{
			printf("Szukana liczba to %d, znajduje sie w komorce nr %d\n", szukana, i);
			fuse = 0;
		}
	}
	if (fuse)
	{
		printf("Liczby nie ma w tablicy\n");
	}
	/*
	double a=0, b=0, c=0;
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
	*/
	system("pause");
    return 0;
}

