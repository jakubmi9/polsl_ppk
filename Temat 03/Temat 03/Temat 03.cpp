// Temat 03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int tab_size = 50;
const int max_num = 32768;

void selection_sort(int* tab)
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

void insert_sort(int* tab)
{

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
	selection_sort(tab);
	cout<<"sorted\n";
	for(int i = 0; i<tab_size; i++)
	{
		cout<<tab[i]<<endl;
	}
	system("pause");
    return 0;
}

