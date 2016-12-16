#pragma once
#include "book.h"
#include "list.h"
using std::string;
class user
{
	private:
	user *_nextuser;
	user *_prevuser;
	public:
	int id;
	string fname;
	string lname;
	user(int,string,string,list<book>);
	~user();
	friend class list<user>;
};

