// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//char code[128];

using namespace std;

void generate()
{
	ofstream ciph;
	ciph.open("code.txt");
	srand(time(0));
	vector<char> cipher;
	for(int i = 32; i<127; i++)
	{
		cipher.push_back(i);
	}
	random_shuffle(cipher.begin(), cipher.end());
	for(int i = 0; i<128; i++)
	{
		if(i<32||i==127)
		{
			//			code[i] = 0;
			ciph<<'\0'<<endl;
		}
		else
		{
			//			code[i] = cipher[i-32];
			ciph<<cipher[i-32]<<endl;
		}
	}
	ciph.close();
	printf("Success!\n");
}

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

void decode(char* i, char* o)
{
	ifstream ifile;
	ifile.open(i);
	if(ifile.is_open())
	{
		ofstream ofile;
		ofile.open(o);
		if(ofile.is_open())
		{
			printf("decoding...");
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
int main(int argc, char* argv[])
{
	//crypt.exe -encode||-decode||-help -src="/*sciezka wejscia*/ -code="/*sciezka do tablicy kodujacej*/" -o="/*sciezka wyjscia*/"
	ifstream cfile;
	switch(argv[1][1])
	{
		case 'h':
			printf("crypt help utility\n\
					usage:\n\
					crypt -generate generates new random codetable\
					crypt -encode -src=\"\" -o=\"\" encodes \'src\' with code.txt and writes it to \'o\'\n\
					crypt -decode -src=\"\" -o=\"\" decodes \'src\' with code.txt and writes it to \'o\'\n\
					crypt -help displays this help message");
			system("pause");
			return 0;
		case 'g':
			printf("Generating code.txt...\n");
			generate();
			return 0;
		case 'e':
			char iname[260] = {0};
			char oname[260] = {0};
			{
				int j = 0;
				int i = 5;
				while(argv[2][i]!='\0')
				{
					iname[j] = argv[2][i];
					i++;
					j++;
				}
			}
			{
				int j = 0;
				int i = 6;
				while(argv[3][i]!='\0')
				{
					oname[j] = argv[3][i];
					i++;
					j++;
				}
			}
			cfile.open("code.txt");
			if(cfile.is_open())
			{
				encode(iname, oname);
				return 0;
			}
			else
			{
				printf("Couldn't find code.txt!\nPlease run crypt -generate first.\nExiting...");
				return 0;
			}
		case 'd':
			char iname[260] = {0};
			char oname[260] = {0};
			{
				int j = 0;
				int i = 5;
				while(argv[2][i]!='\0')
				{
					iname[j] = argv[2][i];
					i++;
					j++;
				}
			}
			{
				int j = 0;
				int i = 6;
				while(argv[3][i]!='\0')
				{
					oname[j] = argv[3][i];
					i++;
					j++;
				}
			}
			//			ifstream cfile;
			cfile.open("code.txt");
			if(cfile.is_open())
			{
				decode(iname, oname);
				return 0;
			}
			else
			{
				printf("Couldn't find code.txt!\nPlease run crypt -generate first.\nExiting...");
				return 0;
			}
		default:
			printf("Invalid runtime argument!\nExiting...");
			return 0;
	}
	system("pause");
}