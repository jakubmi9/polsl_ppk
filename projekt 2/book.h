#pragma once
#include "list.h"
//==============================================================================
/// <summary>object designed to represent a book type</summary>
class book
{
	book *_nextelement;
	book *_prevelement;
	public:
	/// <summary>Author's first name</summary>
	std::string authorfname;
	/// <summary>Author's last name</summary>
	std::string authorlname;
	/// <summary>Title of the book</summary>
	std::string title;
	/// <summary>Genre of the book</summary>
	std::string genre;
	/// <summary>Amount of said book, that's still left in the library</summary>
	int cnt;
	/// <summary>Initialises a new book</summary>
	/// <param name="authorfname">Author's first name</param>
	/// <param name="authorlname">Author's last name</param>
	/// <param name="title">Title of the book</param>
	/// <param name="genre">Genre of the book</param>
	/// <param name="cnt">Amount of said book, that's still left in the library</param>
	book(std::string afname, std::string alname, std::string title, std::string genre, int cnt);
	~book();
	friend class list<book>;
	friend class database;
};
//==============================================================================