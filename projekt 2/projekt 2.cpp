// projekt 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "cpp-shell.h"
#include "exceptions.h"
#include "database.h"
#include "book.h"
#include "user.h"
#include "list.h"
#include "database.h"
using namespace std;
//==============================================================================
#ifdef _DEBUG 
bool DEBUG = true;
#else
bool DEBUG = false;
#endif // _DEBUG
//==============================================================================
int main(int argc, char* argv[])
{
	bool LOADED = false;
	const string startmessage = "libXpress Library Management System alpha\nLicensed under GNU GPLv3";
	const string promptstring = "libxpress";
	sh::shell *ui = new sh::shell(startmessage, promptstring);
	database *db = nullptr;
	while(true)
	{
		try
		{
			while(true)
			{
				ui->prompt();
				if(ui->command[0] == "exit")
				{
					if(LOADED)
					{
						char confirm = 'N';
						cout << "A database is loaded currently. Are you sure? (Y/N)";
						cin >> confirm;
						if(confirm == 'Y' || confirm == 'y')
						{
							delete ui;
							if(DEBUG) system("pause"); return 0;
						}
					}
					delete ui;
					if(DEBUG) system("pause"); return 0;
				}
				else if(ui->command[0] == "load")
				{
					if(LOADED)
					{
						throw new AlreadyLoadedException;
						continue;
					}
					if(ui->command.size() == 2)
					{
						db = new database(ui->command.at(1));
						LOADED = true;
						ui->submodule(ui->command.at(1));
						ui->command.clear();
					}
					else
					{
						if(ui->command.size() > 2)
						{
							throw new InvalidArgumentException;
						}
						else
						{
							ui->subprompt();
							if(ui->command.size() == 2)
							{
								db = new database(ui->command.at(1));
								LOADED = true;
								ui->submodule(ui->command.at(1));
								ui->command.clear();
							}
							else
							{
								throw new InvalidArgumentException;
							}
						}
					}
				}
				else if(ui->command[0] == "flush")
				{
					delete db;
					LOADED = false;
					ui->submodule();
					ui->command.clear();
				}
				else if(ui->command[0] == "status")
				{
					//print current status of the library system
					if(LOADED)
					{
						cout << "A database is currently loaded." << endl;
						cout << "There are " << db->usercount << " registered users.\n";
						cout << db->userswbooks << " of them have unreturned books.\n";
						cout << "There are " << db->bookcount << " different titles.\n";
						cout << db->availablebooks << " copies are currently in the library.\n";
					}
					else
						cout << "No database is open right now" << endl;
					ui->command.clear();
				}
				else if(ui->command[0] == "list")
				{
LIST:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						ui->subprompt();
						goto LIST;
					}
					else if(ui->command.size() == 2)
					{
						if(ui->command.at(1) == "users")
						{
							db->printusers();
						}
						else if(ui->command.at(1) == "books")
						{
							db->printbooks();
						}
						else
						{
							throw new InvalidArgumentException;
						}
					}
					else if(ui->command.size() == 3)
					{
						if(ui->command.at(1) == "users" && ui->command.at(2) == "--unreturned")
						{
							db->printusers("unreturned");
						}
						else if(ui->command.at(1) == "books" && ui->command.at(2) == "--byauthor")
						{
							db->printbooks("byauthor");
						}
						else if(ui->command.at(1) == "books" && ui->command.at(2) == "--bytitle")
						{
							db->printbooks("bytitle");
						}
						else if(ui->command.at(1) == "books" && ui->command.at(2) == "--author")
						{
							ui->subprompt();
							goto LIST;
						}
						else if(ui->command.at(1) == "books" && ui->command.at(2) == "--genre")
						{
							ui->subprompt();
							goto LIST;
						}
						else
						{
							throw new InvalidArgumentException;
						}
					}
					else if(ui->command.size() == 4)
					{
						if(ui->command.at(1) == "list" && ui->command.at(2) == "books" && ui->command.at(3) == "--author")
						{
							db->printbooks("--author", ui->command.at(4));
						}
						else if(ui->command.at(1) == "list" && ui->command.at(2) == "books" && ui->command.at(3) == "--genre")
						{
							db->printbooks("--genre", ui->command.at(4));
						}
					}
					ui->command.clear();
				}
				else if(ui->command[0] == "add")
				{
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					//add new item to the db
					ui->command.clear();
				}
				else if(ui->command[0] == "edit")
				{
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					//edit an existing item
					ui->command.clear();
				}
				else if(ui->command[0] == "delete")
				{
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					//delete item from db
					ui->command.clear();
				}
				else if(ui->command[0] == "borrow")
				{
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					//borrow a book
					ui->command.clear();
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
			delete exp;
			if(DEBUG) system("pause"); else return 0;
		}
		catch(InvalidArgumentException *exp)
		{
			exp->writeout();
			ui->command.clear();
			delete exp;
		}
		catch(out_of_range)
		{
			if(DEBUG) cout << "exception:out_of_range\n";
			ui->subprompt();
			/*ui->command.clear();*/
		}
		catch(AlreadyLoadedException *exp)
		{
			exp->writeout();
			ui->command.clear();
			delete exp;
		}
		catch(CorruptedDatabaseException *exp)
		{
			exp->writeout();
			ui->command.clear();
			delete exp;
		}
		catch(FileNotFoundException *exp)
		{
			exp->writeout();
			ui->command.clear();
			delete exp;
		}
		catch(DatabaseNotLoadedException *exp)
		{
			exp->writeout();
			ui->command.clear();
			delete exp;
		}
	}
}
//==============================================================================