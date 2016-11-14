// Temat 05.cpp : Defines the entry point for the console application.
//
//==============================================================================
#include "stdafx.h"
//==============================================================================
void prog1()
{
	cout << "<prog1>\n";
	bool tab[8][8];
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if(i % 2 == 0 && j % 2 == 0)
			{
				tab[i][j] = 0;
			}
			else if(i % 2 == 0 && j % 2 == 1)
			{
				tab[i][j] = 1;
			}
			else if(i % 2 == 1 && j % 2 == 0)
			{
				tab[i][j] = 1;
			}
			else if(i % 2 == 1 && j % 2 == 1)
			{
				tab[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cout << tab[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "</prog1>\n";
}
//==============================================================================
void prog2()
{
	cout << "<prog2>\n";
	cout << "</prog2>\n";
}
//==============================================================================
void prog3()
{
	cout << "<prog3>\n";
	char tab[4][7] = {
	{'A','B','A','A','B','C','D'},
	{'B','B','A','B','A','D','A'},
	{'A','A','B','A','B','A','B'},
	{'B','A','A','B','A','B','C'}
	};
	char wzor[3] = {'A','B','A'};
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(tab[i][j] == wzor[0] && tab[i][j + 1] == wzor[1] && tab[i][j + 2] == wzor[2])
			{
				cout << "Znaleziono wzorzec! Wiersz  " << i << ", kolumny " << j << "-" << j + 2 << ".\n";
			}
			if(tab[i][j] == wzor[0] && tab[i + 1][j] == wzor[1] && tab[i + 2][j] == wzor[2])
			{
				cout << "Znaleziono wzorzec! Kolumna " << j << ", wiersze " << i << "-" << i + 2 << ".\n";
			}
		}
	}
	cout << "</prog3>\n";
}
//==============================================================================
void prog4()
{
	cout << "<prog4>\n";
	srand(static_cast<unsigned int>(time(0)));
	int tab[10][10];
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			tab[i][j] = rand();
		}
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cout << tab[i][j] << ' ';
		}
		cout << endl;
	}
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(i == j)
			{
				continue;
			}
			else if(i > j)
			{
				tab[i][i] += tab[i][j];
				tab[i][j] = 0;
			}
			else if(j > i)
			{
				tab[j][j] += tab[i][j];
				tab[i][j] = 0;
			}
		}
	}
	cout << endl;
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cout << tab[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "</prog4>\n";
}
//==============================================================================
int main()
{
	prog1();
	prog2();
	prog3();
	prog4();
	system("pause");
}
//==============================================================================