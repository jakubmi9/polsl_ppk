#pragma once
#include "list.h"
using std::string;
class book
{
	book *_nextbook;
	book *_prevbook;
	public:
	string afname;
	string alname;
	string title;
	string genre;
	int cnt;
	book(string, string, string, string, int);
	~book();
	friend class list<book>;
};

