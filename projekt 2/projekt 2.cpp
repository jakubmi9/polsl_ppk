// projekt 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//==============================================================================
class NoArgumentException: public exception
{
	public:
	void writeout()
	{
		printf("0x00000001 No argument passed!\n");
	}
};
class InvalidArgumentException: public exception
{
	public: 
	void writeout()
	{
		printf("0x00000002 Invalid argument!\n");
	}
};
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