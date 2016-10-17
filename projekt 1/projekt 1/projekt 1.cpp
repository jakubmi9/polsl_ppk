// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cipher.h"

using namespace std;

int main(int argc, char* argv[])
{
	//crypt.exe -encode||-decode||-help -src="/*sciezka wejscia*/ -code="/*sciezka do tablicy kodujacej*/" -o="/*sciezka wyjscia*/"
	if(argv[1][1]=='h')
	{
		printf("crypt help utility\n\
usage:\n\
crypt -encode -src=\"\" -code=\"\" -o=\"\" encodes \'src\' with \'code\' and writes it to \'o\'\n\
crypt -decode -src=\"\" -code=\"\" -o=\"\" decodes \'src\' with \'code\' and writes it to \'o\'\n\
crypt -help displays this help message");
		system("pause");
		return 0;
	}
	else if(argv[1][1]=='e')
	{
		char arg1[260] = {0};
		char arg2[260] = {0};
		char arg3[260] = {0};
		{
			int j = 0;
			int i = 5;
			while(argv[2][i]!='\0')
			{
				arg1[j] = argv[2][i];
				i++;
				j++;
			}
		}
		{
			int j = 0;
			int i = 6;
			while(argv[3][i]!='\0')
			{
				arg2[j] = argv[3][i];
				i++;
				j++;
			}
		}
		{
			int j = 0;
			int i = 3;
			while(argv[4][i]!='\0')
			{
				arg3[j] = argv[4][i];
				i++;
				j++;
			}
		}
		ifstream* ifile;
		ifile = new ifstream;
		ifile->open(arg1);
		if(ifile->is_open())
		{
			cipher* cfile;
			cfile = new cipher(arg3);
			ofstream* ofile;
			ofile = new ofstream;
			ofile->open(arg3);
			if(ofile->is_open())
			{
				cfile->encode(ifile, ofile);
			}
			else
			{
				printf("Couldn't open result file for writing!\nExiting...");
			}
			delete(cfile);
			delete(ifile);
			delete(ofile);
		}
		else
		{
			delete(ifile);
			printf("Couldn't find the source file!\nExiting...");
			return 0;
		}
	}
	else if(argv[1][1]=='d')
	{
		char arg1[260] = {0};
		char arg2[260] = {0};
		char arg3[260] = {0};
		{
			int j = 0;
			int i = 5;
			while(argv[2][i]!='\0')
			{
				arg1[j] = argv[2][i];
				i++;
				j++;
			}
		}
		{
			int j = 0;
			int i = 6;
			while(argv[3][i]!='\0')
			{
				arg2[j] = argv[3][i];
				i++;
				j++;
			}
		}
		{
			int j = 0;
			int i = 3;
			while(argv[4][i]!='\0')
			{
				arg3[j] = argv[4][i];
				i++;
				j++;
			}
		}
		ifstream* ifile;
		ifile = new ifstream;
		ifile->open(arg1);
		if(ifile->is_open())
		{
			cipher* cfile;
			cfile = new cipher(arg3);
			ofstream* ofile;
			ofile = new ofstream;
			ofile->open(arg3);
			if(ofile->is_open())
			{
				cfile->decode(ifile, ofile);
			}
			else
			{
				printf("Couldn't open result file for writing!\nExiting...");
			}
			delete(cfile);
			delete(ifile);
			delete(ofile);
		}
		else
		{
			delete(ifile);
			printf("Couldn't find the source file!\nExiting...");
			return 0;
		}
	}
	else
	{
		printf("Invalid runtime argument!\nExiting...");
		return 0;
	}
	system("pause");
	return 0;
}

