#include "stdafx.h"
//==============================================================================
void encode(char* i, char* o, ifstream &cc)
{
	ifstream ifile;
	ifile.open(i);
	if(ifile.is_open())
	{
		ofstream ofile;
		ofile.open(o);
		if(ofile.is_open())
		{
			printf("reading codefile...");
			char tab[128];
			for(int i = 0; i < 128; i++)
			{
				cc >> tab[i];
			}
			printf("done\n");
			printf("encoding...");
			char c;
			while(ifile.get(c))
			{
				ofile << tab[c];
			}
			printf("done\n");
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