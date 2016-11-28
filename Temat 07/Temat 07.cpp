// Temat 07.cpp : Defines the entry point for the console application.
//
//==============================================================================
#include "stdafx.h"

using namespace std;
//==============================================================================
struct punkt
{
	int x = 0;
	int y = 0;
};
//==============================================================================
void zad1()
{
	srand(static_cast<unsigned int>(time(0)));
	punkt tab[5][5];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			tab[i][j] = rand();
		}
	}
	ofstream o;
	o.open("binary",ios::binary);

}
//==============================================================================
int main()
{
	system("pause");
}
//==============================================================================