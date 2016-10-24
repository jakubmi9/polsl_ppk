// Temat 03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int tab_size = 50;
const int max_num = 1000000;

void sort(int* tab)
{
	int min = max_num+1;
	int min_pos = 0;
	for(int i = 0; i<tab_size; i++)
	{
		min = max_num+1;
		for(int j = i; j<tab_size; j++)
		{
			if(tab[j]<min)
			{
				min = tab[j];
				min_pos = j;
			}
		}
		int tmp = min;
		tab[min_pos] = tab[i];
		tab[i] = tmp;
	}
}

int main()
{
	srand(time(0));
	int tab[tab_size];
	cout<<"unsorted\n";
	for(int i = 0; i<tab_size; i++)
	{
		tab[i] = rand()%max_num;
		cout<<tab[i]<<endl;
	}
	sort(tab);
	cout<<"sorted\n";
	for(int i = 0; i<tab_size; i++)
	{
		cout<<tab[i]<<endl;
	}
	system("pause");
    return 0;
}

