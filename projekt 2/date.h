#pragma once
class date
{
	private:
	int _day;
	int _month;
	int _year;
	public:
	std::string to_string();
	int day();
	int month();
	int year();
	date(int, int, int);
	date(std::string);
	date();
	~date();
};

