#include "stdafx.h"
#include "borrowedbook.h"
//#include "date.h"
//==============================================================================
borrowedbook::borrowedbook(int id, std::string bdate)
{
	this->_bookid = id;
	date *tmp = new date(bdate);
	this->_borrowdate = *tmp;
}
//==============================================================================
borrowedbook::~borrowedbook()
{
}
//==============================================================================
int borrowedbook::bookid()
{
	return this->_bookid;
}
//==============================================================================
date borrowedbook::borrowdate()
{
	return this->_borrowdate;
}
//==============================================================================