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
	string line;
	int cnt =0, id;
	while(getline(_i, line))
	{
		if(line == "_begin_db") db = 1;
		else if(line == "_begin_books") bookpart = 1;
		else if(line == "_end_books"&&bookpart) bookpart = 0;
		else if(line == "_begin_users") userpart = 1;
		else if(line == "_end_users"&&userpart) userpart = 0;
		else if(line == "_end_db"&&db) db = 0;
		else if(bookpart&&db)
		{
			int i = 0;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				afname.push_back(line[i]);
			}
			i++;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				alname.push_back(line[i]);
			}
			i++;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				title.push_back(line[i]);
			}
			i++;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				genre.push_back(line[i]);
			}
			i++;
			string num;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				num.push_back(line[i]);
			}
			cnt = stoi(num);
			book *tmp = new book(afname, alname, title, genre, cnt);
			this->bookdb.push(tmp);
			this->bookcnt++;
			delete tmp;
		}
		else if(userpart&&db)
		{
			int i = 0;
			string num;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				num.push_back(line[i]);
			}
			id = stoi(num);
			i++;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				fname.push_back(line[i]);
			}
			i++;
			for(; i < line.length(); i++)
			{
				if(line[i] == ' ')
					break;
				lname.push_back(line[i]);
			}
			i++;
			vector<string> books;
			string bk;
			while(i < line.length())
			{
				for(; i < line.length(); i++)
				{
					if(line[i] == ' ')
						break;
					bk.push_back(line[i]);
				}
				books.push_back(bk);
			}
			user *tmp = new user(id, fname, lname, books);
			this->userdb.push(tmp);
			this->usercnt++;
			if(books.at(0) == "null") { } else
			{
				this->userswbooks++;
			}
			delete tmp;
		}
		else
			throw new CorruptedDatabaseException;
	}
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