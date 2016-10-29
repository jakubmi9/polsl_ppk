#include "stdafx.h"
//==============================================================================
void encode(char* i, char* o)
{
	ifstream ifile;
	ifile.open(i);
	if(ifile.is_open())
	{
		ofstream ofile;
		ofile.open(o);
		if(ofile.is_open())
		{
			printf("encoding...");
			return;
		}
		else
		{
			printf("Couldn't open result file for writing!\nExiting...");
			return;
		}
	}
	else
	{
		printf("Couldn't find the source file!\nExiting...");
		return;
	}
}
//==============================================================================