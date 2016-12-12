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
	ElementBefore->NextElement->PreviousElement = ElementBefore;
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
void PrintHeadToTail(element *&HEAD)
{
	element *END = HEAD;
	for(int i = 0; END; i++)
	{
		cout << "Element " << i << ": " << END->Data << endl;
		END = END->NextElement;
	}
}
//==============================================================================
void PrintTailToHead(element *&TAIL)
{
	element *BEGIN = TAIL;
	for(int i = 0; BEGIN; i++)
	{
		cout << "Element " << i << ": " << BEGIN->Data << endl;
		BEGIN = BEGIN->PreviousElement;
	}
}
//==============================================================================
int main()
{
	element *HEAD = new element, *TAIL = HEAD, *trash = HEAD;
	cout << "initialised list with a random value" << endl;
	PrintHeadToTail(HEAD);
	InsertAtBeginning(HEAD, TAIL, 5);
	cout << "InsertAtBeginning 5" << endl;
	PrintHeadToTail(HEAD);
	InsertAtEnd(HEAD, TAIL, 25);
	cout << "InsertAtEnd 25" << endl;
	PrintHeadToTail(HEAD);
	RemoveElement(HEAD, trash);
	cout << "RemoveElement trash" << endl;
	PrintHeadToTail(HEAD);
	cout << "PrintTailToHead" << endl;
	PrintTailToHead(TAIL);
	DeleteList(HEAD);
	system("pause");
}
//==============================================================================