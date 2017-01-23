#include "stdafx.h"
#include "date.h"
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
	for(; i < datestring.size(); i++)
	{
		if(datestring[i] == '-')
			break;
		num.push_back(datestring[i]);
	}
	this->_month = std::stoi(num);
	num.clear();
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