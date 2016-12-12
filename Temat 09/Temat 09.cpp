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
void InsertAtBeginning(element *&HEAD, element *&TAIL, int Data)
{
	if(HEAD == 0)
	{
		element *NewElement = new element;
		NewElement->Data = Data;
		NewElement->NextElement = nullptr;
		HEAD = NewElement;
	}
	else
	{
		element *NewElement = new element;
		NewElement->Data = Data;
		NewElement->NextElement = HEAD;
		HEAD = NewElement;
	}
}
//==============================================================================
void InsertAtEnd(element *&HEAD, element *&TAIL, int Data)
{
	if(TAIL == 0)
	{
		element *NewElement = new element;
		NewElement->Data = Data;
		NewElement->NextElement = nullptr;
		HEAD->NextElement = NewElement;
		TAIL = HEAD;
	}
	else
	{
		element *NewElement = new element;
		NewElement->Data = Data;
		NewElement->NextElement = nullptr;
		TAIL->NextElement = NewElement;
	}
}
//==============================================================================
void InsertBefore(element *&HEAD, element *&TAIL, int data, element *&obj)
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
void InsertAfter(element *&HEAD, element *&TAIL, int data, element *&obj)
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
void RemoveElement(element *&HEAD, element *&TAIL, element *&obj)
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
void DeleteList(element *&HEAD, element *&TAIL)
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
void PrintList(element *&HEAD, element *&TAIL)
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
	element *HEAD = nullptr, *TAIL = HEAD;
	InsertAtBeginning(HEAD, TAIL, 5);
	InsertAtEnd(HEAD, TAIL, 25);
	PrintList(HEAD, TAIL);
	DeleteList(HEAD, TAIL);
	system("pause");
}
//==============================================================================