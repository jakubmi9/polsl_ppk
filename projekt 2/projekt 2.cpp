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
	const std::string startmessage = "libXpress Library Management System v1.1\nLicensed under GNU GPLv3";
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
				else if(ui->command.at(0) == "load")
				{
LOAD:
					if(LOADED)
					{
						throw new AlreadyLoadedException;
						continue;
					}
					if(ui->command.size() == 1)
					{
						std::cout << "What do you want to load?\n";
						ui->subprompt();
						goto LOAD;
					}
					else if(ui->command.size() == 2)
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
				else if(ui->command.at(0) == "flush")
				{
					delete db;
					LOADED = false;
					ui->submodule();
					ui->command.clear();
				}
				else if(ui->command.at(0) == "status")
				{
					if(LOADED)
					{
						std::cout << "A database is currently loaded." << std::endl;
						std::cout << "There are " << db->usercount() << " registered users.\n";
						std::cout << db->userswbooks() << " of them have overdue books.\n";
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
						if(ui->command.at(1) == "users" && ui->command.at(2) == "--overdue")
						{
							db->printusers("overdue");
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
						else
							throw new InvalidArgumentException;
					}
					else 
						throw new InvalidArgumentException;
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
							std::cout << "Syntax:\n<author's first name> <author's last name> <title> <genre> <quantity on site>\n";
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
						std::vector<borrowedbook> tmp;
						user *newuser = new user(db->lastuserid() + 1, ui->command.at(2), ui->command.at(3), tmp);
						db->adduser(newuser);
					}
					else
					{
						std::cout << "should never happen...?\n";
					}
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
							std::cout << "Syntax:\n<author's first name> <author's last name> <title> <genre> <quantity left>\n";
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
					ui->command.clear();
				}
				else if(ui->command.at(0) == "borrow")
				{
BORROW:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						std::cout << "Syntax:\n<book's unique id number> <user's unique id number>\n";
						ui->subprompt();
						goto BORROW;
					}
					else if(ui->command.size() == 3)
					{
						std::cout << db->borrow(stoi(ui->command.at(1)), stoi(ui->command.at(2)));
					}
					else
					{
						throw new InvalidArgumentException;
					}
					ui->command.clear();
				}
				else if(ui->command.at(0) == "return")
				{
BOOKRETURN:
					if(!LOADED)
						throw new DatabaseNotLoadedException;
					if(ui->command.size() == 1)
					{
						std::cout << "Syntax:\n<book's unique id number> <user's unique id number>\n";
						ui->subprompt();
						goto BOOKRETURN;
					}
					else if(ui->command.size() == 3)
					{
						std::cout << db->bookreturn(stoi(ui->command.at(1)), stoi(ui->command.at(2)));
					}
					else
					{
						throw new InvalidArgumentException;
					}
					ui->command.clear();
				}
				else if(ui->command.at(0) == "help")
				{
					if(LOADED)
					{
						std::cout << "libXpress Help Utility\n\
available commands:\n\
exit                                    | exits the program\n\
help                                    | displays this help message\n\
status                                  | displays current status of the library\n\
flush                                   | saves current library state to the file it was originally loaded from\n\
list users [--overdue]                  | displays list of all users [users with overdue books]\n\
list books [--byauthor | --bytitle]     | displays list of all books [books sorted by author/title]\n\
list books [--author | --genre] <query> | displays only books of author/genre specified by query\n\
[borrow | return] <bookid> <userid>     | borrows/returns book for specified user\n\
add book <author's first name> <author's last name> <title> <genre> <quantity> \n\
^^^^                                    | adds new book to the database\n\
add user <first name> <last name>       | adds new user to the database\n\
delete [book | user] <id>               | deletes book/user of said id from the database\n\
edit [book|user] <id>                   | displays interactive prompt for editing a database entry\n\
";
					}
					else
					{
						std::cout << "libXpress Help Utility\n\
available commands:\n\
exit                                    | exits the program\n\
help                                    | displays this help message\n\
status                                  | displays current status of the library\n\
load <filename>                         | loads libXpress database from disk\n\
";
					}
					
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