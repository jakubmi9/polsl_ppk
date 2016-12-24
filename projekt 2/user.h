#pragma once
#include <vector>
#include "list.h"
//==============================================================================
class user
{
	private:
	user *_nextuser;
	user *_prevuser;
	public:
	int id;
	std::string fname;
	std::string lname;
	std::vector<std::string> books;
	user(int,std::string,std::string,std::vector<std::string>);
	~user();
	friend class list<user>;
};
//==============================================================================