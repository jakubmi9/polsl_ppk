// Temat 10.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//==============================================================================
struct Tree
{
	int Value = 0;
	Tree* LeftChild = nullptr;
	Tree* RightChild = nullptr;
};
//==============================================================================
void Insert(Tree *&ROOT, int Value)
{
	static char LR;
	if(ROOT == nullptr)
	{
		Tree* tmp = new Tree;
		tmp->Value = Value;
		ROOT = tmp;
		//LR == 'L' ? ROOT->LeftChild = tmp : ROOT->RightChild = tmp;
		return;
	}
	if(ROOT->Value > Value)
	{
		LR = 'L';
		Insert(ROOT->LeftChild, Value);
	}
	else
	{
		LR = 'R';
		Insert(ROOT->RightChild, Value);
	}
}
//==============================================================================
void PrintTree(Tree *&ROOT)
{
	if(!ROOT)
		return;
	std::cout << ROOT->Value << ':';
	if(ROOT->LeftChild)
	{
		std::cout << ROOT->LeftChild->Value << ',';
	}
	else
	{
		std::cout << "nullptr,";
	}
	if(ROOT->RightChild)
	{
		std::cout << ROOT->RightChild->Value << std::endl;
	}
	else
	{
		std::cout << "nullptr\n";
	}
	PrintTree(ROOT->LeftChild);
	PrintTree(ROOT->RightChild);
}
//==============================================================================
void DeleteTree()
{

}
//==============================================================================
int main()
{
	Tree* ROOT = new Tree;
	ROOT->Value = 20;
	Insert(ROOT, 10);
	Insert(ROOT, 50);
	Insert(ROOT, 5);
	Insert(ROOT, 60);
	Insert(ROOT, 8);
	Insert(ROOT, 30);
	Insert(ROOT, 25);
	Insert(ROOT, 40);
	PrintTree(ROOT);
	DeleteTree();
	system("pause");
}
//==============================================================================