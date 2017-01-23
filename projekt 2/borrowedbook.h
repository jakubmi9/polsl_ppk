#pragma once
#include "date.h"
//==============================================================================
class borrowedbook
{
	private:
	bool _overdue;
	int _bookid;
	date _borrowdate;
	public:
	///
	borrowedbook(int, std::string);
	///
	borrowedbook(int, int, int, int);
	~borrowedbook();
	///
	int bookid();
	///
	date borrowdate();
	///
	bool overdue();
};
//==============================================================================