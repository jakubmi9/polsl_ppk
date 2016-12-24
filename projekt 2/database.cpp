#include "stdafx.h"
#include "database.h"
using namespace std;
database::database(string file)
{
	this->_fname = file;
	ifstream _i(file);
	string afname, alname, title, genre, fname, lname;
	string temp;
	int cnt, id;
	while(_i >> afname >> alname >> title >> genre >> cnt)
	{
		book *tmp = new book(afname, alname, title, genre, cnt);
		this->bookdb.push(tmp);
		delete tmp;
	}
	while(_i >> id >> fname >> lname /*>> books*/)
	{
		list<book> books;
		user *tmp = new user(id, fname, lname, books);
		while(_i >> temp)
		{
			books.push(temp)
		}
		this->userdb.push(tmp);
		delete tmp;
	}
	_i.close();
}

database::~database()
{
	ofstream _o(this->_fname);
	//flush db to disk
	_o.close();
}
