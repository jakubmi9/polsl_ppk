#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
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
class CorruptedDatabaseException: public std::exception
{
	private:
	protected:
	public:
	void writeout();
};
//==============================================================================
class FileNotFoundException: public std::exception
{
	private:
	protected:
	public:
	void writeout();
};
//==============================================================================
class DatabaseNotLoadedException: public std::exception
{
	private:
	protected:
	public:
	void writeout();
};
//==============================================================================
#endif // !EXCEPTIONS_H