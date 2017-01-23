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
	const std::string startmessage = "libXpress Library Management System alpha\nLicensed under GNU GPLv3";
	const std::string promptstring = "libxpress";
	sh::shell *ui = new sh::shell(startmessage, promptstring);
	database *db = nullptr;
	while(true)
	{
		try
		{
			while(true)
			{
				ui->prompt();
				if(ui->command.at(0) == "exit")
				{
					if(LOADED)
					{
						char confirm = 'N';
						std::cout << "A database is loaded currently. Are you sure? (Y/N)";
						std::cin >> confirm;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(confirm == 'Y' || confirm == 'y')
						{
							delete ui;
							if(DEBUG) system("pause"); return 0;
						}
						else
						{
							ui->command.clear();
						}
					}
					else
					{
						delete ui;
						if(DEBUG) system("pause"); return 0;
					}
				}
				else if(ui->command.at(0) == "help")
				{

				}
				else if(ui->command.at(0) == "load")
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
				else if(ui->command.at(0) == "flush")
				{
					delete db;
					LOADED = false;
					ui->submodule();
					ui->command.clear();
				}
				else if(ui->command.at(0) == "status")
				{
					//print current status of the library system
					if(LOADED)
					{
						std::cout << "A database is currently loaded." << std::endl;
						std::cout << "There are " << db->usercount() << " registered users.\n";
						std::cout << db->userswbooks() << " of them have unreturned books.\n";
						std::cout << "There are " << db->bookcount() << " different titles.\n";
						std::cout << db->availablebooks() << " copies are currently in the library.\n";
					}
					else
						std::cout << "No database is open right now" << std::endl;
					ui->command.clear();
				}
				else if(ui->command.at(0) == "list")
				{
LIST:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						std::cout << "What do you want to list?\n";
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
							std::cout << "Please specify an author:\n";
							ui->subprompt();
							goto LIST;
						}
						else if(ui->command.at(1) == "books" && ui->command.at(2) == "--genre")
						{
							std::cout << "Please specify a genre to be listed:\n";
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
						if(ui->command.at(1) == "books" && ui->command.at(2) == "--author")
						{
							db->printbooks("--author", ui->command.at(3));
						}
						else if(ui->command.at(1) == "books" && ui->command.at(2) == "--genre")
						{
							db->printbooks("--genre", ui->command.at(3));
						}
					}
					ui->command.clear();
				}
				else if(ui->command.at(0) == "add")
				{
ADD:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						std::cout << "What do you want to add?\n";
						ui->subprompt();
						goto ADD;
					}
					else if(ui->command.size() == 2)
					{
						if(ui->command.at(1) == "book")
						{
							std::cout << "Syntax:\n<author's first name> <author's last name> <title> <genre> <amount currently on site>\n";
							ui->subprompt();
							goto ADD;
						}
						else if(ui->command.at(1) == "user")
						{
							std::cout << "Syntax:\n<user's first name> <user's last name>\n";
							ui->subprompt();
							goto ADD;
						}
					}
					else if(ui->command.at(1) == "book" && ui->command.size() < 7)
					{
						throw new InsufficientArgumentException;
					}
					else if(ui->command.at(1) == "user" && ui->command.size() < 4)
					{
						throw new InsufficientArgumentException;
					}
					else if(ui->command.at(1) == "book" && ui->command.size() == 7)
					{
						book *newbook = new book(db->lastbookid() + 1, ui->command.at(2), ui->command.at(3), ui->command.at(4), ui->command.at(5), stoi(ui->command.at(6)));
						db->addbook(newbook);
					}
					else if(ui->command.at(1) == "user" && ui->command.size() == 4)
					{
						std::vector<std::string> tmp;
						tmp.push_back("null");
						user *newuser = new user(db->lastuserid() + 1, ui->command.at(2), ui->command.at(3), tmp);
						db->adduser(newuser);
					}
					else
					{
						std::cout << "should never happen...?\n";
					}
					//add new item to the db
					ui->command.clear();
				}
				else if(ui->command.at(0) == "edit")
				{
EDIT:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						std::cout << "What do you want to edit?\n";
						ui->subprompt();
						goto EDIT;
					}
					else if(ui->command.size() == 2)
					{
						if(ui->command.at(1) == "book")
						{
							std::cout << "Syntax:\n<book's unique id number>\n";
							ui->subprompt();
							goto EDIT;
						}
						else if(ui->command.at(1) == "user")
						{
							std::cout << "Syntax:\n<user's unique id number>\n";
							ui->subprompt();
							goto EDIT;
						}
					}
					else if(ui->command.size() == 3)
					{
						if(ui->command.at(1) == "book")
						{
							std::cout << "Syntax:\n<author's first name> <author's last name> <title> <genre> <amount left>\n";
							ui->subprompt();
							if(ui->command.size() < 8)
								throw new InsufficientArgumentException;
							db->editbook(stoi(ui->command.at(2)), ui->command.at(3), ui->command.at(4), ui->command.at(5), ui->command.at(6), stoi(ui->command.at(7)));
						}
						else if(ui->command.at(1) == "user")
						{
							std::cout << "Syntax:\n<user's first name> <user's last name>\n";
							ui->subprompt();
							if(ui->command.size() < 5)
								throw new InsufficientArgumentException;
							db->edituser(stoi(ui->command.at(2)), ui->command.at(3), ui->command.at(4));
						}
					}
					//edit an existing item
					ui->command.clear();
				}
				else if(ui->command.at(0) == "delete")
				{
DELETE:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						std::cout << "What do you want to delete?\n";
						ui->subprompt();
						goto DELETE;
					}
					else if(ui->command.size() == 2)
					{
						if(ui->command.at(1) == "book")
						{
							std::cout << "Syntax:\n<book's unique id number>\n";
							ui->subprompt();
							goto DELETE;
						}
						else if(ui->command.at(1) == "user")
						{
							std::cout << "Syntax:\n<user's unique id number>\n";
							ui->subprompt();
							goto DELETE;
						}
					}
					else if(ui->command.size() == 3)
					{
						if(ui->command.at(1) == "book")
						{
							db->delbook(stoi(ui->command.at(2)));
						}
						else if(ui->command.at(1) == "user")
						{
							db->deluser(stoi(ui->command.at(2)));
						}
					}
					//delete item from 
					ui->command.clear();
				}
				else if(ui->command.at(0) == "borrow")
				{
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					//borrow a book
					ui->command.clear();
				}
				else if(ui->command.at(0) == "return")
				{
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					//return a book
					ui->command.clear();
				}
				else
				{
					throw new InvalidArgumentException;
				}
			}
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
		catch(std::out_of_range)
		{
			std::cout << "0x00000009 Element of specified index doesn't exist!\n";
			ui->command.clear();
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
		catch(InsufficientArgumentException *exp)
		{
			exp->writeout();
			ui->command.clear();
			delete exp;
		}
	}
}
//==============================================================================