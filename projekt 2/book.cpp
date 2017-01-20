#include "stdafx.h"
#include "book.h"
//==============================================================================
book::book(int bookid, std::string afname, std::string alname, std::string title, std::string genre, int cnt)
{
	this->authorfname = afname;
	this->authorlname = alname;
	this->title = title;
	this->genre = genre;
	this->cnt = cnt;
	this->_bookid = bookid;
}
//==============================================================================
book::~book()
{

}
//==============================================================================