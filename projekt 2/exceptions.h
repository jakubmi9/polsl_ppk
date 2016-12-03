#pragma once
//==============================================================================
class NoArgumentException: public std::exception
{
	private:
	protected:
	public:
	void writeout();
};
//==============================================================================
class InvalidArgumentException: public std::exception
{
	private:
	protected:
	public:
	void writeout();
};
//==============================================================================
class AlreadyLoadedException: public std::exception
{
	private:
	protected:
	public:
	void writeout();
};
//==============================================================================