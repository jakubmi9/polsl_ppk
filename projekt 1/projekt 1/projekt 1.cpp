// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cipher.h"

using namespace std;

int main(int argc, char* argv [])
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
		ifstream* ifile;
		ifile = new ifstream;
		ifile->open("original.txt");
		if(ifile->is_open())
		{
			cipher* cfile;
			cfile = new cipher("coding_table.txt");
			ofstream* ofile;
			ofile = new ofstream;
			ofile->open("result.txt");
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
		ifstream* ifile;
		ifile = new ifstream;
		ifile->open("original.txt");
		if(ifile->is_open())
		{
			cipher* cfile;
			cfile = new cipher("coding_table.txt");
			ofstream* ofile;
			ofile = new ofstream;
			ofile->open("result.txt");
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

