// projekt 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//==============================================================================
int main(char* argv[], int argc)
{
	bool DEBUG = 1;
	if(argc == 1)
	{
		printf("0x00000001 No argument passed!\n");
		if(DEBUG) system("pause"); else return 0;
	}
	else if(!strcmp(argv[1], "-status"))
	{
		//print current status of the library system
		if(DEBUG) system("pause"); else return 0;
	}
	else
	{
		printf("0x0000002 Invalid argument!\n");
		if(DEBUG) system("pause"); else return 0;
	}
}
//==============================================================================