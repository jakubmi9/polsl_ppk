// projekt 1.cpp : Defines the entry point for the console application.
//crypt.exe -generate||-encode||-decode||-help -src="/*sciezka wejscia*/" -code="/*sciezka do tablicy kodujacej*/" -o="/*sciezka wyjscia*/"
//
//debug routine:
//-generate
//-encode -src="original.txt" -o="encoded.txt"
//-decode -src="encoded.txt" -o="decoded.txt"
//==============================================================================
#include "stdafx.h"
//==============================================================================
int main(int argc, char* argv[])
{
	printf("crypt encryption utility alpha\n");
	if(argc == 1)
	{
		printf("Invalid runtime argument!\n\
usage:\n\
crypt -generate	\t\tgenerates new random codetable\n\
crypt -encode -src=\"\" -o=\"\"	encodes \'src\' with a codetable and writes it to \'o\'\n\
crypt -decode -src=\"\" -o=\"\"	decodes \'src\' with a codetable and writes it to \'o\'\n\
crypt -help	\t\tdisplays this help message\n");
		return 0;
	}
	switch(argv[1][1])
	{
		case 'h':
		{
			printf("usage:\n\
crypt -generate	\t\tgenerates new random codetable\n\
crypt -encode -src=\"\" -o=\"\"	encodes \'src\' with a codetable and writes it to \'o\'\n\
crypt -decode -src=\"\" -o=\"\"	decodes \'src\' with a codetable and writes it to \'o\'\n\
crypt -help	\t\tdisplays this help message\n");
			break;
		}
		case 'g':
		{
			printf("Generating code.txt...");
			generate();
			break;
		}
		case 'e':
		{
			char iname[260] = {0};
			char oname[260] = {0};
			{
				int j = 0;
				int i = 5;
				while(argv[2][i] != '\0')
				{
					iname[j] = argv[2][i];
					i++;
					j++;
				}
			}
			{
				int j = 0;
				int i = 3;
				while(argv[3][i] != '\0')
				{
					oname[j] = argv[3][i];
					i++;
					j++;
				}
			}
			ifstream cfile;
			cfile.open("code.txt");
			if(cfile.is_open())
			{
				encode(iname, oname, cfile);
				break;
			}
			else
			{
				printf("Couldn't find code.txt!\nPlease run crypt -generate first.\nExiting...");
				break;
			}
		}
		case 'd':
		{
			char iname[260] = {0};
			char oname[260] = {0};
			{
				int j = 0;
				int i = 5;
				while(argv[2][i] != '\0')
				{
					iname[j] = argv[2][i];
					i++;
					j++;
				}
			}
			{
				int j = 0;
				int i = 3;
				while(argv[3][i] != '\0')
				{
					oname[j] = argv[3][i];
					i++;
					j++;
				}
			}
			ifstream cfile;
			cfile.open("code.txt");
			if(cfile.is_open())
			{
				decode(iname, oname, cfile);
				break;
			}
			else
			{
				printf("Couldn't find code.txt!\nPlease run crypt -generate first.\nExiting...");
				break;
			}
		}
		default:
		{
			printf("Invalid runtime argument!\nExiting...");
			break;
		}
	}
	return 0;
}
//==============================================================================