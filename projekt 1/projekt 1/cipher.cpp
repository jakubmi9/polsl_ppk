#include "stdafx.h"
#include "cipher.h"

using namespace std;


cipher::cipher(const char src[100])
{
	ifstream charcode;
	charcode.open(src);
	if(charcode.is_open())
	{
		char cipher[26] = {0};
		for(int i = 0; i<26; i++)
		{
			charcode>>cipher[i];
		}
		printf("Successfully imported a code table\n");
	}
	else
	{
		printf("Couldn't find the code table!\nExiting...");
	}
}


cipher::~cipher()
{
	//delete(charcode);
}
