// projekt 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "exceptions.h"
using namespace std;
//==============================================================================
///<summary>Entry point for the application</summary>
///<returns>0 if completed successfully</returns>
///<param name="argc">Number of arguments passed from the command line</param>
///<param name="argv">Two dimensional array of chars containing cmd launch arguments. argv[0] is always name of the executable.</param>
int main(int argc, char* argv[])
{
	bool DEBUG = 1;
	try
	{
		//error when run w/out args
		if(argc == 1)
		{
			throw new NoArgumentException;
		}
		//print current status of the library system
		else if(!strcmp(argv[1], "status"))
		{
			if(DEBUG) system("pause"); else return 0;
		}
		//lists books or users
		else if(!strcmp(argv[1], "list"))
		{
			if(DEBUG) system("pause"); else return 0;
		}
		//adds an item to the database
		else if(!strcmp(argv[1], "add"))
		{
			if(DEBUG) system("pause"); else return 0;
		}
		//edit an item
		else if(!strcmp(argv[1], "edit"))
		{
			if(DEBUG) system("pause"); else return 0;
		}
		//deletes item from the database
		else if(!strcmp(argv[1], "delete"))
		{
			if(DEBUG) system("pause"); else return 0;
		}
		//borrows a book to a user
		else if(!strcmp(argv[1], "borrow"))
		{
			if(DEBUG) system("pause"); else return 0;
		}
		//error on non specified argument
		else
		{
			throw new InvalidArgumentException;
		}
	}
	catch(NoArgumentException *exp)
	{
		exp->writeout();
		if(DEBUG) system("pause"); else return 0;
	}
	catch(InvalidArgumentException *exp)
	{
		exp->writeout();
		if(DEBUG) system("pause"); else return 0;
	}
}
//==============================================================================