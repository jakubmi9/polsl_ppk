// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cipher.h"

using namespace std;

int main()
{
	ifstream txt;
	txt.open("original.txt");
	if(txt.is_open())
	{
		cipher* c;
		c = new cipher("coding_table.txt");

		delete(c);
	}
	else
	{
		printf("Couldn't find the source file!\nExiting...");
	}
	system("pause");
	return 0;
}

