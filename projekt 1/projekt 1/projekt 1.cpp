// projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cipher.h"

using namespace std;

int main(int argc, char* argv [])
{
	//crypt.exe -encode||-decode||-help -src="/*sciezka wejscia*/ -code="/*sciezka do tablicy kodujacej*/" -o="/*sciezka wyjscia*/"
	if(argv[1]=="-help")
	{
		printf("crypt help utility\n\
usage:\n\
crypt -encode -src=\"\" -code=\"\" -o=\"\" encodes \'src\' with \'code\' and writes it to \'o\'\n\
crypt -decode -src=\"\" -code=\"\" -o=\"\" decodes \'src\' with \'code\' and writes it to \'o\'\n\
crypt -help displays this help message\n");
		return 0;
	}
	ifstream* txt;
	txt = new ifstream;
	txt->open("original.txt");
	if(txt->is_open())
	{
		//printf("Successfully opened the source file\n");
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

