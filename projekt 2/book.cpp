#include "stdafx.h"
#include "book.h"
//==============================================================================
book::book(string afname, string alname, string title, string genre, int cnt)
{
	this->afname = afname;
	this->alname = alname;
	this->title = title;
	this->genre = genre;
	this->cnt = cnt;
}
//==============================================================================
book::~book()
{

}
//==============================================================================