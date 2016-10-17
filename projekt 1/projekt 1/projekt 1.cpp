// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>


using namespace std;
int main()
{
	ifstream txt;
	txt.open("original.txt");
	if(txt.is_open())
	{
		ifstream charcode;
		charcode.open("coding_table.txt");
		if(charcode.is_open())
		{
			char cipher[26] = {0};
			for(int i = 0; i<26; i++)
			{
				charcode>>cipher[i];
				cout<<cipher[i];
			}
		}
		else
		{
			printf("Couldn't find the code table!\nExiting...");
		}
	}
	else
	{
		printf("Couldn't find the source file!\nExiting...");
	}
	system("pause");
	return 0;
}

