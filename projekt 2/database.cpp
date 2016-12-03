#include "stdafx.h"
#include "database.h"
using namespace std;
database::database(string file)
{
	this->_fname = file;
	ifstream _i(file);
	//read db from disk
	_i.close();
}

database::~database()
{
	ofstream _o(this->_fname);
	//flush db to disk
	_o.close();
}
