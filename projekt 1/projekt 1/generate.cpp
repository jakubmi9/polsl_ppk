#include "stdafx.h"
//==============================================================================
void generate()
{
	ofstream ciph;
	ciph.open("code.txt");
	srand(static_cast<unsigned int>(time(0)));
	vector<char> cipher;
	for(int i = 32; i < 127; i++)
	{
		cipher.push_back(i);
	}
	random_shuffle(cipher.begin(), cipher.end());
	for(int i = 0; i < 128; i++)
	{
		if(i < 32 || i == 127)
		{
			ciph << '\0' << endl;
		}
		else
		{
			ciph << cipher[i - 32] << endl;
		}
	}
	ciph.close();
	printf("Success!\n");
}
//==============================================================================