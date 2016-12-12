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
void InsertAfter(element *&HEAD, int data, element *&obj)
{
	element *ElementBefore = HEAD;
	while(!(ElementBefore == obj))
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
void RemoveElement(element *&HEAD, element *&obj)
{
	element *ElementBefore = HEAD;
	while(!(ElementBefore->NextElement == obj))
	{
		ElementBefore = ElementBefore->NextElement;
	}
	element *ElementAfter = ElementBefore->NextElement->NextElement;
	delete obj;
	ElementBefore->NextElement = ElementAfter;
}
//==============================================================================
void DeleteList(element *&HEAD)
{
	element *CurrentElement = HEAD;
	element *NextElement = HEAD->NextElement;
	while(CurrentElement->NextElement)
	{
		delete CurrentElement;
		CurrentElement = NextElement;
		NextElement = CurrentElement->NextElement;
	}
}
//==============================================================================
void PrintList(element *&HEAD)
{
	element *END = HEAD;
	int i = 0;
	for(int i = 0; END; i++)
	{
		cout << "Element " << i << ": " << END->Data << endl;
		END = END->NextElement;
	}
}
//==============================================================================
int main()
{
	element *List;
	List = new element;
	List->Data = 5;
	InsertAtBeginning(List, 0);
	InsertAtEnd(List, 25);
	InsertAtEnd(List, 125);
	InsertBefore(List, 50, List->NextElement->NextElement->NextElement);
	InsertAtEnd(List, 625);
	InsertAfter(List, 3125, List->NextElement->NextElement->NextElement->NextElement->NextElement);
	RemoveElement(List, List->NextElement->NextElement->NextElement);
	PrintList(List);
	DeleteList(List);
	system("pause");
}
//==============================================================================