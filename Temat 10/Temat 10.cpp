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

}
//==============================================================================
void PrintTree()
{

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
	PrintTree();
	DeleteTree();
	system("pause");
}
//==============================================================================