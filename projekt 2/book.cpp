#include "stdafx.h"
#include "book.h"
//==============================================================================
book::book(int bookid, std::string afname, std::string alname, std::string title, std::string genre, int cnt)
{
	this->_bookid = bookid;
	this->_authorfname = afname;
	this->_authorlname = alname;
	this->_title = title;
	this->_genre = genre;
	this->_cnt = cnt;
}
//==============================================================================
book::~book()
{

}
//==============================================================================
int book::bookid()
{
	return this->_bookid;
}
//==============================================================================
std::string book::authorfname()
{
	return this->_authorfname;
}
//==============================================================================
std::string book::authorlname()
{
	return this->_authorlname;
}
//==============================================================================
std::string book::title()
{
	return this->_title;
}
//==============================================================================
std::string book::genre()
{
	return this->_genre;
}
//==============================================================================
int book::cnt()
{
	return this->_cnt;
}
//==============================================================================