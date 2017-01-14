#include "stdafx.h"
#include "book.h"
//==============================================================================
book::book(std::string afname, std::string alname, std::string title, std::string genre, int cnt)
{
	this->authorfname = afname;
	this->authorlname = alname;
	this->title = title;
	this->genre = genre;
	this->cnt = cnt;
}
//==============================================================================
book::~book()
{

}
//==============================================================================