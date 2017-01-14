#pragma once
#include "book.h"
#include "user.h"
#include "list.h"
/// <summary>Database object, that contains list of users and list of books</summary>
class database
{
	private:
	std::string _fname;
	list<book> bookdb;
	list<user> userdb;
	public:
	/// <summary>Count of unique users in the database</summary>
	int usercnt = 0;
	/// <summary>Count of unique books if the database</summary>
	int bookcnt = 0;
	/// <summary>Count of users, that possess unreturned books</summary>
	int userswbooks = 0;
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
};