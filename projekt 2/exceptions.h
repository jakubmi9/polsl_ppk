#pragma once
//==============================================================================
class NoArgumentException: public exception
{
	public:
	void writeout();
};
//==============================================================================
class InvalidArgumentException: public exception
{
	public:
	void writeout();
};
//==============================================================================