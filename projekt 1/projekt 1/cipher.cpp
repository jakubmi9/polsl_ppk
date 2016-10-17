#include "stdafx.h"																			  
#include "cipher.h"																			  

using namespace std;

char* ctable;

cipher::cipher(const char src[100])
{
	ifstream* codefile;
	codefile = new ifstream;
	codefile->open(src);
	if(codefile->is_open())
	{
		tableopened = 1;
		ctable = new char[26];
		for(int i = 0; i<26; i++)
		{
			*codefile>>ctable[i];
		}
		codefile->close();
		delete(codefile);
		//printf("Successfully imported a code table\n");
	}
	else
	{
		printf("Couldn't find the code table!\nExiting...");
	}
}

cipher::~cipher()
{
	delete(ctable);
}

void cipher::encode(ifstream* src,ofstream* tgt)
{
	if(!tableopened)
	{
		return;
	}
	cout<<"encoding...";
	//...
}

void cipher::decode(ifstream* src, ofstream* tgt)
{
	if(!tableopened)
	{
		return;
	}
	//...
	cout<<"decoding...";

}