#include "stdafx.h"
#include "database.h"
#include "exceptions.h"
using namespace std;
//==============================================================================
database::database(string file)
{
	this->_fname = file;
	ifstream _i(file);
	if(!_i.is_open())
		throw new FileNotFoundException;
	bool db = 0, userpart = 0, bookpart = 0;
	string afname, alname, title, genre, fname, lname;
	string line;
	int cnt = 0, id;
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
			afname.clear();
			alname.clear();
			title.clear();
			genre.clear();
			num.clear();
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
				bk.clear();
			}
			user *tmp = new user(id, fname, lname, books);
			this->userdb.push(tmp);
			this->usercnt++;
			if(books.at(0) == "null")
			{
			}
			else
			{
				this->userswbooks++;
			}
			num.clear();
			fname.clear();
			lname.clear();
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
	_o << "_begin_db\n_begin_books\n";
	book *currentbook = this->bookdb.head;
	while(currentbook)
	{
		_o << currentbook->afname << ' ' << currentbook->alname << ' ' << currentbook->title << ' ' << currentbook->genre << ' ' << currentbook->cnt << endl;
		currentbook = currentbook->_nextbook;
	}
	_o << "_end_books\n_begin_users\n";
	user *currentuser = this->userdb.head;
	while(currentuser)
	{
		_o << currentuser->id << ' ' << currentuser->fname << ' ' << currentuser->lname << ' ' << currentuser->books.at(0);
		if(currentuser->books.size() > 1)
		{
			for(int i = 1; i < currentuser->books.size(); i++)
			{
				_o << currentuser->books.at(i) << ' ';
			}
		}
		_o << endl;
		currentuser = currentuser->_nextuser;
	}
	_o << "_end_users\n_end_db";
	_o.close();
}
//==============================================================================
void database::printusers()
{
	this->userdb.print();
}
//==============================================================================
void database::printusers(std::string irr)
{
	this->userdb.print("switch");
}
//==============================================================================
void database::printbooks()
{
	this->bookdb.print();
}
//==============================================================================