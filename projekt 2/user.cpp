#include "stdafx.h"
#include "user.h"
//==============================================================================
user::user(int id, std::string fname, std::string lname, std::vector<std::string> books)
{
	this->id = id;
	this->userfname = fname;
	this->userlname = lname;
	this->borrowedbooks = books;
}
//==============================================================================
user::~user()
{
}
//==============================================================================