#pragma once
#include "date.h"
class borrowedbook
{
	private:
	int _bookid;
	date _borrowdate;
	public:
	///
	borrowedbook(int, std::string);
	///
	int bookid();
	///
	date borrowdate();
	~borrowedbook();
};

