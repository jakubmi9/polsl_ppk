// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cipher.h"

using namespace std;

int main()
{
	ifstream* txt;
	txt = new ifstream;
	txt->open("original.txt");
	if(txt->is_open())
	{
		printf("Successfully opened the source file\n");
		cipher* file;
		file = new cipher("coding_table.txt");
		//...
		delete(file);
		delete(txt);
	}
	else
	{
		delete(txt);
		printf("Couldn't find the source file!\nExiting...");
	}
	system("pause");
	return 0;
}

