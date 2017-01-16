#pragma once
#include "book.h"
#include "user.h"
#include "list.h"
#ifndef DATABASE_H
#define DATABASE_H
/// <summary>Database object, that contains list of users and list of books</summary>
class database
{
	private:
	std::string _filename;
	list<book> _bookdb;
	list<user> _userdb;
	public:
	/// <summary>Count of unique users in the database</summary>
	int usercount = 0;
	/// <summary>Count of unique titles in the database</summary>
	int bookcount = 0;
	/// <summary>Count of users, that possess unreturned books</summary>
	int userswbooks = 0;
	/// <summary>Count of books, that are physically in the library</summary>
	int availablebooks = 0;
	/// <summary>Creates new database filled with values from disk</summary>
	/// <param name="file">name of the file, that contains the database</param>
	database(std::string file);
	~database();
	/// <summary>Lists all users in the database</summary>
	void printusers();
	/// <summary>Lists only users that have unreturned books</summary>
	void printusers(std::string irrelevant);
	/// <summary>Lists all books in the database</summary>
	void printbooks();
	/// <summary>Lists all books sorted by author or title</summary>
	/// <param name="modeswitch">"--byauthor" or "--bytitle"</param>
	void printbooks(std::string modeswitch);
	/// <summary>Lists only books specified by the query</summary>
	/// <param name="modeswitch">"author" or "genre"</param>
	/// <param name="query">Any string that will be used to filter the list</param>
	void printbooks(std::string modeswitch, std::string query);
};
#endif // !DATABASE_H