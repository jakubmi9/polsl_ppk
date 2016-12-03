// projekt 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "cpp-shell.h"
#include "exceptions.h"
#include "database.h"
using namespace std;
//==============================================================================
///<summary>Entry point for the application</summary>
///<returns>0 if completed successfully</returns>
///<param name="argc">Number of arguments passed from the command line</param>
///<param name="argv">Two dimensional array of chars containing cmd launch arguments. argv[0] is always name of the executable.</param>
int main(int argc, char* argv[])
{
	bool DEBUG = true;
	bool LOADED = false;
	const string g = "libXpress Library Management System alpha\nLicensed under GNU GPLv3";
	const string p = "libxpress";
	sh::shell *main = new sh::shell(g, p);
	database *db = 0;
	while(true)
	{
		try
		{
			while(true)
			{
				main->prompt();
				if(main->command[0] == "exit")
				{
					delete main;
					if(DEBUG) system("pause"); return 0;
				}
				else if(main->command[0] == "load")
				{
					if(LOADED)
					{
						throw new AlreadyLoadedException;
						continue;
					}
					if(main->command.size() == 2)
					{
						database *db = new database(main->command.at(1));
						LOADED = true;
						main->submodule(main->command.at(1));
						main->command.clear();
					}
					else
					{
						if(main->command.size() > 2)
						{
							throw new InvalidArgumentException;
						}
						else
						{
							main->subprompt();
							if(main->command.size() == 2)
							{
								db = new database(main->command.at(1));
								LOADED = true;
								main->submodule(main->command.at(1));
								main->command.clear();
							}
							else
							{
								throw new InvalidArgumentException;
							}
						}
					}
					//if(main->command.size() == 1)
					//{
					//	while(true)
					//	{
					//		main->subprompt();
					//		if(main->command.size() > 2)
					//		{
					//			throw new InvalidArgumentException;
					//			break;
					//		}
					//		else
					//		{
					//			//load database with name in command[1]
					//		}
					//	}
					//}
				}
				else if(main->command[0] == "unload")
				{
					//unloads the database to a file
					delete db;
					LOADED = false;
					main->submodule();
					main->command.clear();
				}
				else if(main->command[0] == "status")
				{
					//print current status of the library system
					main->command.clear();
				}
				else if(main->command[0] == "list")
				{
					//check for more arguments if none found throw a subshell asking for them
					main->command.clear();
				}
				else if(main->command[0] == "add")
				{
					//add new item to the db
					main->command.clear();
				}
				else if(main->command[0] == "edit")
				{
					//edit an existing item
					main->command.clear();
				}
				else if(main->command[0] == "delete")
				{
					//delete item from db
					main->command.clear();
				}
				else if(main->command[0] == "borrow")
				{
					//borrow a book
					main->command.clear();
				}
				else
				{
					throw new InvalidArgumentException;
				}
			}
			////error when run w/out args
			//if(argc == 1)
			//{
			//	throw new NoArgumentException;
			//}
			////print current status of the library system
			//else if(!strcmp(argv[1], "status"))
			//{
			//	if(DEBUG) system("pause"); else return 0;
			//}
			////lists books or users
			//else if(!strcmp(argv[1], "list"))
			//{
			//	if(DEBUG) system("pause"); else return 0;
			//}
			////adds an item to the database
			//else if(!strcmp(argv[1], "add"))
			//{
			//	if(DEBUG) system("pause"); else return 0;
			//}
			////edit an item
			//else if(!strcmp(argv[1], "edit"))
			//{
			//	if(DEBUG) system("pause"); else return 0;
			//}
			////deletes item from the database
			//else if(!strcmp(argv[1], "delete"))
			//{
			//	if(DEBUG) system("pause"); else return 0;
			//}
			////borrows a book to a user
			//else if(!strcmp(argv[1], "borrow"))
			//{
			//	if(DEBUG) system("pause"); else return 0;
			//}
			////error on non specified argument
			//else
			//{
			//	throw new InvalidArgumentException;
			//}
		}
		catch(NoArgumentException *exp)
		{
			exp->writeout();
			if(DEBUG) system("pause"); else return 0;
		}
		catch(InvalidArgumentException *exp)
		{
			exp->writeout();
			main->command.clear();
		}
		catch(out_of_range)
		{
			cout << "exception:out_of_range\n";
			main->subprompt();
			/*main->command.clear();*/
		}
		catch(AlreadyLoadedException *exp)
		{
			exp->writeout();
			main->command.clear();
		}
	}
}
//==============================================================================