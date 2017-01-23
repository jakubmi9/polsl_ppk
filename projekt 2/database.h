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
	int _usercount = 0;
	int _bookcount = 0;
	int _userswbooks = 0;
	int _availablebooks = 0;
	public:
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
	/// <summary>Count of unique users in the database</summary>
	int usercount();
	/// <summary>Count of unique titles in the database</summary>
	int bookcount();
	/// <summary>Count of users, that possess unreturned books</summary>
	int userswbooks();
	/// <summary>Count of books, that are physically in the library</summary>
	int availablebooks();
	///
	int lastbookid();
	///
	int lastuserid();
	///
	void addbook(book * obj);
	///
	void adduser(user * obj);
	///
	void delbook(int bookid);
	///
	void deluser(int userid);
	///
	void editbook(int bookid, std::string afname, std::string alname, std::string title, std::string genre, int cnt);
	///
	void edituser(int userid, std::string ufname, std::string ulname);
	///
	void borrow(int bookid, int userid);
};
#endif // !DATABASE_H