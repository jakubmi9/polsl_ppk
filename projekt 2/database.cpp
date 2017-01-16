#include "stdafx.h"
#include "database.h"
#include "exceptions.h"
using namespace std;
//==============================================================================
database::database(string file)
{
	this->_filename = file;
	ifstream _dbfile(file);
	if(!_dbfile.is_open())
		throw new FileNotFoundException;
	bool db = 0, userpart = 0, bookpart = 0;
	string afname, alname, title, genre, fname, lname;
	string line;
	int cnt = 0, id;
	while(getline(_dbfile, line))
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
			this->availablebooks += cnt;
			book *tmp = new book(afname, alname, title, genre, cnt);
			this->_bookdb.push(tmp);
			this->bookcount++;
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
			this->_userdb.push(tmp);
			this->usercount++;
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
	_dbfile.close();
}
//==============================================================================
database::~database()
{
	ofstream _dbfile(this->_filename);
	_dbfile << "_begin_db\n_begin_books\n";
	book *currentbook = this->_bookdb.head;
	while(currentbook)
	{
		_dbfile << currentbook->authorfname << ' ' << currentbook->authorlname << ' ' << currentbook->title << ' ' << currentbook->genre << ' ' << currentbook->cnt << endl;
		currentbook = currentbook->_nextelement;
	}
	_dbfile << "_end_books\n_begin_users\n";
	user *currentuser = this->_userdb.head;
	while(currentuser)
	{
		_dbfile << currentuser->id << ' ' << currentuser->userfname << ' ' << currentuser->userlname << ' ' << currentuser->borrowedbooks.at(0);
		if(currentuser->borrowedbooks.size() > 1)
		{
			for(int i = 1; i < currentuser->borrowedbooks.size(); i++)
			{
				_dbfile << currentuser->borrowedbooks.at(i) << ' ';
			}
		}
		_dbfile << endl;
		currentuser = currentuser->_nextelement;
	}
	_dbfile << "_end_users\n_end_db";
	_dbfile.close();
}
//==============================================================================
void database::printusers()
{
	this->_userdb.print();
}
//==============================================================================
void database::printusers(std::string irr)
{
	this->_userdb.print("switch");
}
//==============================================================================
void database::printbooks()
{
	this->_bookdb.print();
}
//==============================================================================
void database::printbooks(std::string modeswitch)
{
	this->_bookdb.print(modeswitch);
}
//==============================================================================
void database::printbooks(std::string modeswitch, std::string query)
{
	this->_bookdb.print(modeswitch, query);
}
//==============================================================================