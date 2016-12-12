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
		HEAD = NewElement;
		TAIL = HEAD;
	}
	else
	{
		element *NewElement = new element;
		NewElement->Data = Data;
		NewElement->NextElement = nullptr;
		NewElement->PreviousElement = TAIL;
		TAIL->NextElement = NewElement;
		TAIL = NewElement;
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
	element *HEAD = new element, *TAIL = HEAD, *trash = HEAD;
	cout << "initialised list with a random value"<< endl;
	PrintList(HEAD);
	InsertAtBeginning(HEAD, TAIL, 5);
	cout << "InsertAtBeginning 5" << endl;
	PrintList(HEAD);
	InsertAtEnd(HEAD, TAIL, 25);
	cout << "InsertAtEnd 25" << endl;
	PrintList(HEAD);
	RemoveElement(HEAD, trash);
	cout << "RemoveElement trash" << endl;
	PrintList(HEAD);
	DeleteList(HEAD);
	system("pause");
}
//==============================================================================