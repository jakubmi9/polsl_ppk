#pragma once
#include <vector>
#include "list.h"
#ifndef USER_H
#define USER_H
//==============================================================================
/// <summary>object designed to represent a single user</summary>
class user
{
	private:
	user *_nextelement;
	user *_prevelement;
	int _userid;
	std::string _userfname;
	std::string _userlname;
	std::vector<std::string> _borrowedbooks;
	public:
	/// <summary>Returns unique ID number of the user.</summary>
	int userid();
	/// <summary>Returns user's first name.</summary>
	std::string userfname();
	/// <summary>Returns user's last name.</summary>
	std::string userlname();
	/// <summary>Returns a vector containing names of all the books, currently borrowed by the user.</summary>
	std::vector<std::string> borrowedbooks();
	/// <summary>initialises a new user</summary>
	/// <param name="id">Unique ID number of the user.</param>
	/// <param name="userfname">User's first name.</param>
	/// <param name="userlname">User's last name.</param>
	/// <param name="borrowedbooks">Vector containing names of all the books, currently borrowed by the user.</param>
	user(int id, std::string fname, std::string lname, std::vector<std::string> books);
	~user();
	friend class list<user>;
	friend class database;
};
//==============================================================================
#endif // !USER_H