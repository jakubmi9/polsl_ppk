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
	cout << "<zad1>\n";
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
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			o << tab[i][j].x << ' ' << tab[i][j].y << ' ';
		}
	}
	o.close();
	ifstream ifile;
	ifile.open("zad1.bin", ios::binary);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			int x;
			int y;
			ifile >> x >> y;
			cout << "punkt " << i << ',' << j << "=(" << x << ',' << y << ")\n";
		}
	}
	cout << "</zad1>\n";
}
//==============================================================================
void zad2()
{
	cout << "<zad2>\n";
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
	ifstream ifile;
	ifile.open("zad2.txt");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			int x;
			int y;
			ifile >> x >> y;
			cout << "punkt " << i << ',' << j << "=(" << x << ',' << y << ")\n";
		}
	}
	cout << "</zad2>\n";
}
//==============================================================================
void zad3(int argc, char* argv[])
{
	cout << "<zad3>\n";
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
	cout << "</zad3>\n";
}
//==============================================================================
void zad4(int argc, char* argv[])
{
	cout << "<zad4>\n";
	ifstream plik1, plik2;
	plik1.open(argv[1]);
	plik2.open(argv[2]);
	queue<int> p1;
	queue<int> p2;
	int tmp;
	while(plik1 >> tmp)
	{
		p1.push(tmp);
	}
	while(plik2 >> tmp)
	{
		p2.push(tmp);
	}
	ofstream plik3;
	plik3.open("zad4_3.txt");
	while(p1.empty() != 1 || p2.empty() != 1)
	{
		if(p1.empty())
		{
			plik3 << p2.front() << endl;
			p2.pop();
		}
		else if(p2.empty())
		{
			plik3 << p1.front() << endl;
			p1.pop();
		}
		else if(p1.front() > p2.front())
		{
			plik3 << p2.front() << endl;
			p2.pop();
		}
		else if(p1.front() < p2.front())
		{
			plik3 << p1.front() << endl;
			p1.pop();
		}
		else
		{
			plik3 << p1.front() << endl;
			p1.pop();
		}
	}
	cout << "</zad4>\n";
}
//==============================================================================
int main(int argc, char* argv[])
{
	//zad1();
	//zad2();
	//zad3(argc, argv);															//program.exe zad3.txt
	zad4(argc, argv);															//program.exe zad4_1.txt zad4_2.txt
	system("pause");
}
//==============================================================================