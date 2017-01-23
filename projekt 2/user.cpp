#include "stdafx.h"
#include "user.h"
//==============================================================================
user::user(int id, std::string fname, std::string lname, std::vector<borrowedbook> books)
{
	this->_userid = id;
	this->_userfname = fname;
	this->_userlname = lname;
	this->_borrowedbooks = books;
	for(int i = 0; books.size(); i++)
	{
		if(books.at(i).overdue() == true)
			_flagged = 1;
		break;
	}
}
//==============================================================================
user::~user()
{
}
//==============================================================================
int user::userid()
{
	return this->_userid;
}
//==============================================================================
std::string user::userfname()
{
	return this->_userfname;
}
//==============================================================================
std::string user::userlname()
{
	return this->_userlname;
}
//==============================================================================
std::vector<borrowedbook> user::borrowedbooks()
{
	return this->_borrowedbooks;
}
//==============================================================================
bool user::flagged()
{
	return this->_flagged;
}
//==============================================================================