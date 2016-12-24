#include "stdafx.h"
#include "database.h"
#include "exceptions.h"
using namespace std;
//==============================================================================
database::database(string file)
{
	this->_fname = file;
	ifstream _i(file);
	bool db = 0, userpart = 0, bookpart = 0;
	string afname, alname, title, genre, fname, lname;
	string temp;
	int cnt, id;
	_i >> temp; if(temp == "_begin_db") db = 1; else throw new CorruptedDatabaseException;
	_i >> temp; if(temp == "_begin_books") bookpart = 1; else throw new CorruptedDatabaseException;
	while(_i >> afname >> alname >> title >> genre >> cnt)
	{
		book *tmp = new book(afname, alname, title, genre, cnt);
		this->bookdb.push(tmp);
		this->bookcnt++;
		delete tmp;
	}
	_i >> temp; if(temp == "_end_books") bookpart = 0; else throw new CorruptedDatabaseException;
	_i >> temp; if(temp == "_begin_users") userpart = 1; else throw new CorruptedDatabaseException;
	while(_i >> id >> fname >> lname /*>> books*/)
	{
		vector<string> books;
		user *tmp = new user(id, fname, lname, books);
		while(_i >> temp)
		{
			if(temp == "null")
			{
				this->userswbooks++;
				continue;
			}
			else
				books.push_back(temp);
		}
		this->userdb.push(tmp);
		this->usercnt++;
		delete tmp;
	}
	_i >> temp; if(temp == "_end_users") userpart = 0; else throw new CorruptedDatabaseException;
	_i >> temp; if(temp == "_end_db") db = 0; else throw new CorruptedDatabaseException;
	if(db || userpart || bookpart)
		throw new CorruptedDatabaseException;
	_i.close();
}
//==============================================================================
database::~database()
{
	ofstream _o(this->_fname);
	while(this->bookdb.head)
	{
		_o << this->bookdb.head->afname << ' ' << this->bookdb.head->alname << ' ' << this->bookdb.head->title << ' ' << this->bookdb.head->genre << ' ' << this->bookdb.head->cnt << endl;
		book *tmp = this->bookdb.head;
		//this->bookdb.head = this->bookdb.head->_nextbook;
		delete tmp;
	}
	_o << endl;
	while(this->userdb.head)
	{
		_o << this->userdb.head->id << ' ' << this->userdb.head->fname << ' ' << this->userdb.head->lname << ' ' << this->userdb.head->books.at(0);
		if(this->userdb.head->books.size() > 1)
		{
			for(int i = 1; i < this->userdb.head->books.size(); i++)
			{
				_o << this->userdb.head->books.at(i) << ' ';
			}
		}
		_o << endl;
		user *tmp = this->userdb.head;
		//this->userdb.head = this->userdb.head->_nextuser;
		delete tmp;
	}
	//flush db to disk
	_o.close();
}
//==============================================================================