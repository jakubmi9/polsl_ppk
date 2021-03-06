#include "stdafx.h"
#include "date.h"
date::date()
{
}
//==============================================================================
date::date(int day, int month, int year)
{
	this->_day = day;
	this->_month = month;
	this->_year = year;
}
//==============================================================================
date::date(std::string datestring)
{
	std::string num;
	int i = 0;
	for(; i < datestring.size(); i++)
	{
		if(datestring[i] == '-')
			break;
		num.push_back(datestring[i]);
	}
	this->_day = std::stoi(num);
	num.clear();
	i++;
	for(; i < datestring.size(); i++)
	{
		if(datestring[i] == '-')
			break;
		num.push_back(datestring[i]);
	}
	this->_month = std::stoi(num);
	num.clear();
	i++;
	for(; i < datestring.size(); i++)
	{
		if(datestring[i] == '-')
			break;
		num.push_back(datestring[i]);
	}
	this->_year = std::stoi(num);
	num.clear();
}
//==============================================================================
date::~date()
{
}
//==============================================================================
std::string date::to_string()
{
	return std::to_string(this->_day) + '-' + std::to_string(this->_month) + '-' + std::to_string(this->_year);
}
//==============================================================================
int date::to_raw()
{
	if(this->_month < 3)
		this->_year--, this->_month += 12;
	return 365 * this->_year + this->_year / 4 - this->_year / 100 + this->_year / 400 + (153 * this->_month - 457) / 5 + this->_day - 306;
}
//==============================================================================
int date::day()
{
	return this->_day;
}
//==============================================================================
int date::month()
{
	return this->_month;
}
//==============================================================================
int date::year()
{
	return this->_year;
}
//==============================================================================
int date::dayspassed()
{
	time_t rawtime;
	time(&rawtime);
	tm *tmp = new tm;
	localtime_s(tmp, &rawtime);
	date *now = new date(tmp->tm_mday, (tmp->tm_mon + 1), (tmp->tm_year + 1900));
	return now->to_raw()-this->to_raw();
}
//==============================================================================