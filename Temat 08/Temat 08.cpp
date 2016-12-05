// Temat 08.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
using namespace std;
//==============================================================================
struct element
{
	int Data;
	element *NextElement;
};
//==============================================================================
void InsertAtBeginning(element *&HEAD, int Data)
{
	element *NewElement = new element;
	NewElement->Data = Data;
	NewElement->NextElement = HEAD;
	HEAD = NewElement;
}
//==============================================================================
int main()
{
	element *List;
	List = new element;
	List->Data = 5;
	InsertAtBeginning(List, 25);
	InsertAtBeginning(List, 125);
	cout << List->NextElement->NextElement->Data;
	system("pause");
}
//==============================================================================