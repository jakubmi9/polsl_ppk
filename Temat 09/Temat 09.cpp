// Temat 09.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
using namespace std;
//==============================================================================
struct element
{
	element *PreviousElement = nullptr, *NextElement = nullptr;
	int Data;
};
//==============================================================================
int main()
{
	element *HEAD = new element, *TAIL = HEAD;
	system("pause");
}
//==============================================================================