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
			tab[i][j].x = rand();
			tab[i][j].y = rand();
		}
	}
	ofstream o;
	o.open("zad1.bin", ios::binary);
	//do something...
}
//==============================================================================
void zad2()
{
	srand(static_cast<unsigned int>(time(0)));
	punkt tab[5][5];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			tab[i][j].x = rand();
			tab[i][j].y = rand();
		}
	}
	ofstream o;
	o.open("zad2.txt");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			o << tab[i][j].x << ' ' << tab[i][j].y << endl;
		}
	}
	o.close();
	ifstream i;
	i.open("zad2.txt");
	for(int i = 0; i < 5; i++)
	{
		/*for(int j = 0; j < 5; j++)
		{
			int x;
			int y;
			i >> x >> y;
			cout << "punkt " << i << ',' << j << "=(" << x << ',' << y << ")\n";
		}*/
	}
}
//==============================================================================
void zad3(int argc, char* argv[])
{
	ifstream i;
	i.open(argv[1]);
	unsigned int tab[128] = {0};
	char tmp;
	while(i >> tmp)
		tab[static_cast<unsigned int>(tmp)]++;
	for(int i = 32; i < 127; i++)
	{
		cout << static_cast<char>(i) << '=' << tab[i] << endl;
	}
}
//==============================================================================
void zad4()
{

}
//==============================================================================
int main(int argc, char* argv[])
{
	zad2();
	zad3(argc, argv);
	system("pause");
}
//==============================================================================