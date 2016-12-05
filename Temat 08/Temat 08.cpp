// Temat 08.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
using namespace std;
//==============================================================================
struct element
{
	int Data;
	element *NextElement = nullptr;
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
void InsertAtEnd(element *&HEAD, int Data)
{
	element *END = HEAD;
	while(END->NextElement)
	{
		END = END->NextElement;
	}
	element *NewElement = new element;
	NewElement->Data = Data;
	NewElement->NextElement = nullptr;
	END->NextElement = NewElement;
}
//==============================================================================
void InsertBefore(element *&HEAD, int data, element *&obj)
{
	element *ElementBefore = HEAD;
	while(!(ElementBefore->NextElement == obj))
	{
		ElementBefore = ElementBefore->NextElement;
	}
	element *ElementAfter = ElementBefore->NextElement;
	element *NewElement = new element;
	NewElement->Data = data;
	NewElement->NextElement = ElementAfter;
	ElementBefore->NextElement = NewElement;
}
//==============================================================================
void InsertAfter()
{

}
//==============================================================================
void RemoveElement()
{

}
//==============================================================================
void DeleteList()
{

}
//==============================================================================
void PrintList()
{

}
//==============================================================================
int main()
{
	element *List;
	List = new element;
	List->Data = 5;
	InsertAtEnd(List, 25);
	InsertAtEnd(List, 125);
	InsertAtEnd(List, 625);
	InsertBefore(List, 50, List->NextElement->NextElement);
	cout << List->NextElement->NextElement->Data;
	system("pause");
}
//==============================================================================