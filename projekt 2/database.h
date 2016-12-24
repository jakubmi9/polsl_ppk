#pragma once
#include "book.h"
#include "user.h"
#include "list.h"
class database
{
	private:
	std::string _fname;
	list<book> bookdb;
	list<user> userdb;
	public:
	int usercnt = 0;
	int bookcnt = 0;
	int userswbooks = 0;
	database(std::string file);
	~database();
};