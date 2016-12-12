#include "stdafx.h"
#include "book.h"
#include "user.h"
#include "list.h"



user::user(int id, string fname, string lname, list<book> books)
{
	this->id = id;
	this->fname = fname;
	this->lname = lname;
}


user::~user()
{
}
