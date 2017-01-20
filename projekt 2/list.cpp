#include "stdafx.h"
#include "list.h"
#include "user.h"
#include "book.h"
#include <vector>
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
		std::vector<book*> *sorted = new std::vector<book*>;
		while(sorted->size() < this->length())
		{
			book *_current = this->head();
			std::string minimum = "z";
			book *minelement = nullptr;
			do
			{
				if(_current->authorlname() < minimum)
				{
					bool fuse = 1;
					if(!sorted->empty())
						for(int i = 0; i < sorted->size(); i++)
						{
							if(sorted->at(i) == _current)
							{
								fuse = 0;
								break;
							}
						}
					if(fuse)
					{
						minimum = _current->authorlname();
						minelement = _current;
					}
				}
				_current = _current->_nextelement;
			}while(_current);
			sorted->push_back(minelement);
		}
		for(int i = 0; i < sorted->size(); i++)
		{
			std::cout << "Book ID: " << sorted->at(i)->bookid() << " | " << sorted->at(i)->authorfname() << ' ' << sorted->at(i)->authorlname() << " - " << sorted->at(i)->title() << " | " << sorted->at(i)->genre() << " | Left in the library: " << sorted->at(i)->cnt() << std::endl;
		}
	}
	else if(modeswitch == "bytitle")
	{
		std::vector<book*> *sorted = new std::vector<book*>;
		while(sorted->size() < this->length())
		{
			book *_current = this->head();
			std::string minimum = "z";
			book *minelement = nullptr;
			do
			{
				if(_current->title() < minimum)
				{
					bool fuse = 1;
					if(!sorted->empty())
						for(int i = 0; i < sorted->size(); i++)
						{
							if(sorted->at(i) == _current)
							{
								fuse = 0;
								break;
							}
						}
					if(fuse)
					{
						minimum = _current->title();
						minelement = _current;
					}
				}
				_current = _current->_nextelement;
			} while(_current);
			sorted->push_back(minelement);

		}
		for(int i = 0; i < sorted->size(); i++)
		{
			std::cout << "Book ID: " << sorted->at(i)->bookid() << " | " << sorted->at(i)->authorfname() << ' ' << sorted->at(i)->authorlname() << " - " << sorted->at(i)->title() << " | " << sorted->at(i)->genre() << " | Left in the library: " << sorted->at(i)->cnt() << std::endl;
		}
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