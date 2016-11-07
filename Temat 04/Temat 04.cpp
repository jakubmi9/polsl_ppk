// Temat 04.cpp : Defines the entry point for the console application.
//==============================================================================
#include "stdafx.h"
int x = 10;
//==============================================================================
void foo(int x, static const int y, int &z)
{
	x = 100;
	//y = 100;																	//blad!
	z = 100;
}

//==============================================================================
void _find(string &s, string &f)
{
	int streak = 0;
	for(int i = 0; i < f.length(); i++)
	{
		if(f[i] == s[0])
		{
			streak = 1;
			for(int j = 0; j < s.length(); j++)
			{
				if(f[i+j] == s[j])
				{
					continue;
				}
				else
				{
					streak = 0;
					break;
				}
			}
			if(streak)
			{
				cout << "found string in text @char" << i << endl;
			}
			/*streak++;
			continue;*/
		}
		//if(streak==1)
		//{
		//	if(f[i] == s[1])
		//	{
		//		streak++;
		//		continue;
		//	}
		//	streak = 0;
		//	continue;
		//}
	}
}
//==============================================================================
int main()
{
/*	int a = 10;
	int b = 20;
	int c = 30;
	foo(a, b, c);*/
	string txt;
	string ex;
	cin >> txt;
	cin >> ex;
	_find(ex, txt);
	system("pause");
}
//==============================================================================