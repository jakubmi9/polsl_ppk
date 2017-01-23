#pragma once
#include "list.h"
#ifndef BOOK_H
#define BOOK_H
//==============================================================================
/// <summary>object designed to represent a book type</summary>
class book
{
	book *_nextelement;
	book *_prevelement;
	int _bookid;
	std::string _authorfname;
	std::string _authorlname;
	std::string _title;
	std::string _genre;
	int _cnt;
	public:
	/// <summary>Initialises a new book</summary>
	/// <param name="bookid">Unique id number of the book</param>
	/// <param name="afname">Author's first name</param>
	/// <param name="alname">Author's last name</param>
	/// <param name="title">Title of the book</param>
	/// <param name="genre">Genre of the book</param>
	/// <param name="cnt">Amount of said book, that's still left in the library</param>
	book(int bookid, std::string afname, std::string alname, std::string title, std::string genre, int cnt);
	~book();
	/// <summary>Unique id of the book</summary>
	int bookid();
	/// <summary>Author's first name</summary>
	std::string authorfname();
	/// <summary>Author's last name</summary>
	std::string authorlname();
	/// <summary>Title of the book</summary>
	std::string title();
	/// <summary>Genre of the book</summary>
	std::string genre();
	/// <summary>Amount of said book, that's still left in the library</summary>
	int cnt();
	friend class list<book>;
	friend class database;
};
//==============================================================================
#endif // !BOOK_H