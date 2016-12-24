#include "stdafx.h"
#include "user.h"
//==============================================================================
user::user(int id, std::string fname, std::string lname, std::vector<std::string> books)
{
	this->id = id;
	this->fname = fname;
	this->lname = lname;
	this->books = books;
}
//==============================================================================
user::~user()
{
}
//==============================================================================