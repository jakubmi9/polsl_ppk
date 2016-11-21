// Temat 06.cpp : Defines the entry point for the console application.
//
//==============================================================================
#include "stdafx.h"
using namespace std;
//==============================================================================
struct punkt
{
	int x;
	int y;
};
//==============================================================================
void zad1(punkt* pktv, int pktc, double* wynikv, int wynikc)
{
	cout << "<zad1>\n";
	int count = 0;
	for(int i = 0; i < pktc; i += 3)
	{
		double BokA = sqrt((pktv[i + 1].x - pktv[i].x) + (pktv[i + 1].y - pktv[i].y));
		double BokB = sqrt((pktv[i + 2].x - pktv[i + 1].x) + (pktv[i + 2].y - pktv[i + 1].y));
		double BokC = sqrt((pktv[i + 2].x - pktv[i].x) + (pktv[i + 2].y - pktv[i].y));
		double p = (BokA + BokB + BokC) / 2;
		double Heron = sqrt(p*(p - BokA)*(p - BokB)*(p - BokC)); 
		wynikv[count] = Heron; 
		count++;
	}
	cout << "</zad1>\n";
}
//==============================================================================
void zad2()
{
	cout << "<zad2>\n";
	cout << "</zad2>\n";
}
//==============================================================================
void zad3()
{
	cout << "<zad3>\n";
	cout << "</zad3>\n";
}
//==============================================================================
int main()
{
	/*punkt p;
	p.x = 10;
	p.y = 20;
	int a = 10;
	punkt p2 = {10,20};*/
	punkt tab1[30];
	double wy1[10];
	zad1(tab1, 30, wy1, 10);
	zad2();
	zad3();
	system("pause");
}
//==============================================================================