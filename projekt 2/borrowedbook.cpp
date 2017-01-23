#include "stdafx.h"
#include "borrowedbook.h"


borrowedbook::borrowedbook(int id, std::string bdate)
{
	this->_bookid = id;
	date *tmp = new date(bdate);
	this->_borrowdate = *tmp;
}


borrowedbook::~borrowedbook()
{
}
