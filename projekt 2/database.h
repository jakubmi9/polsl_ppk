#pragma once
#include "book.h"
#include "user.h"
#include "list.h"
class database
{
	private:
	std::string _fname;
	public:
	list<book> bookdb;
	//list<user> userdb;
	database(std::string file);
	~database();
};