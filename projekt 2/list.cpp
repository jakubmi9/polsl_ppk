#include "stdafx.h"
#include "list.h"
#include "user.h"
#include "book.h"
//==============================================================================
template< >
void list<user>::print()
{
	user *_current = this->head();
	while(_current)
	{
		std::cout << "User ID: " << _current->userid() << " | " << _current->userfname() << ' ' << _current->userlname() << " | Borrowed books: ";
		for(int i = 0; i < _current->borrowedbooks().size(); i++)
		{
			if(_current->borrowedbooks().at(0) == "null")
				std::cout << "none";
			else
			{
				std::cout << _current->borrowedbooks().at(i);
			}
		}
		std::cout << std::endl;
		_current = _current->_nextelement;
	}
}
//==============================================================================
template< >
void list<user>::print(std::string irrelevant)
{
	user *_current = this->head();
	while(_current)
	{
		if(_current->borrowedbooks().at(0) == "null")
		{
			_current = _current->_nextelement;
			continue;
		}
		else
		{
			std::cout << "User ID: " << _current->userid() << " | " << _current->userfname() << ' ' << _current->userlname() << " | Borrowed books: ";
			for(int i = 0; i < _current->borrowedbooks().size(); i++)
			{
				if(_current->borrowedbooks().at(0) == "null")
					std::cout << "none";
				else
				{
					std::cout << _current->borrowedbooks().at(i) << ", ";
				}
			}
			std::cout << std::endl;
			_current = _current->_nextelement;

		}
	}
}
//==============================================================================
template< >
void list<book>::print()
{
	book *_current = this->head();
	while(_current)
	{
		std::cout << "Book ID: " << _current->bookid() << " | " << _current->authorfname() << ' ' << _current->authorlname() << " - " << _current->title() << " | " << _current->genre() << " | Left in the library: " << _current->cnt() << std::endl;
		_current = _current->_nextelement;
	}
}
//==============================================================================
template< >
void list<book>::print(std::string modeswitch)
{
	if(modeswitch == "byauthor")
	{
		//TBD: List all books, sorted by author's last name
	}
	else if(modeswitch == "bytitle")
	{
		//TBD: List all books, sorted by title
	}
}
//==============================================================================
template< >
void list<book>::print(std::string modeswitch, std::string query)
{
	if(modeswitch == "--author")
	{
		book *_current = this->head();
		while(_current)
		{
			if(_current->authorlname() == query)
			{
				std::cout << "Book ID: " << _current->bookid() << " | " << _current->authorfname() << ' ' << _current->authorlname() << " - " << _current->title() << " | " << _current->genre() << " | Left in the library: " << _current->cnt() << std::endl;
			}
			_current = _current->_nextelement;
		}
	}
	else if(modeswitch == "--genre")
	{
		book *_current = this->head();
		while(_current)
		{
			if(_current->genre() == query)
			{
				std::cout << "Book ID: " << _current->bookid() << " | " << _current->authorfname() << ' ' << _current->authorlname() << " - " << _current->title() << " | " << _current->genre() << " | Left in the library: " << _current->cnt() << std::endl;
			}
			_current = _current->_nextelement;
		}
	}
}
//==============================================================================