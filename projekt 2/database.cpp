#include "stdafx.h"
#include "database.h"
using namespace std;
database::database(string file)
{
	this->_fname = file;
	ifstream _i(file);
	string afname, alname, title, genre;
	int cnt;
	while(_i >> afname >> alname >> title >> genre >> cnt)
	{
		book *tmp = new book(afname, alname, title, genre, cnt);
		this->bookdb.push(tmp);
	}
	_i.close();
}

database::~database()
{
	ofstream _o(this->_fname);
	//flush db to disk
	_o.close();
}
