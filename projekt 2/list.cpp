#include "stdafx.h"
#include "list.h"
#include "user.h"
#include "book.h"
#include "date.h"
#include "borrowedbook.h"
//==============================================================================
template< >
void list<user>::print()
{
	user *_current = this->head();
	while(_current)
	{
		std::cout << "User ID: " << _current->userid() << " | " << _current->userfname() << ' ' << _current->userlname() << " | Borrowed books: ";
		if(_current->borrowedbooks().empty() == true)
			std::cout << "none";
		else
		{
			for(int i = 0; i < _current->borrowedbooks().size(); i++)
			{
				std::cout << _current->borrowedbooks().at(i).bookid() << " on " << _current->borrowedbooks().at(i).borrowdate().to_string() << ", ";
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
		if(_current->borrowedbooks().empty())
		{
			_current = _current->_nextelement;
			continue;
		}
		else
		{
			std::cout << "User ID: " << _current->userid() << " | " << _current->userfname() << ' ' << _current->userlname() << " | Borrowed books: ";
			if(_current->borrowedbooks().empty() == true)
				std::cout << "none";
			else
			{
				for(int i = 0; i < _current->borrowedbooks().size(); i++)
				{
					std::cout << _current->borrowedbooks().at(i).bookid() << " on " << _current->borrowedbooks().at(i).borrowdate().to_string() << ", ";
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
			} while(_current);
			sorted->push_back(minelement);
		}
		for(int i = 0; i < sorted->size(); i++)
		{
			std::cout << "Book ID: " << sorted->at(i)->bookid() << " | " << sorted->at(i)->authorfname() << ' ' << sorted->at(i)->authorlname() << " - " << sorted->at(i)->title() << " | " << sorted->at(i)->genre() << " | Left in the library: " << sorted->at(i)->cnt() << std::endl;
		}
		delete sorted;
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
		delete sorted;
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
template< >
void list<book>::remove(int id)
{
	book *_target = this->at(id);
	book *prev = _target->_prevelement;
	book *next = _target->_nextelement;
	if(prev)
		prev->_nextelement = next;
	if(next)
		next->_prevelement = prev;
	if(_target == this->head())
		this->_head = next;
	if(_target == this->tail())
		this->_tail = prev;
	delete _target;
}
//==============================================================================
template< >
void list<user>::remove(int id)
{
	user *_target = this->at(id);
	user *prev = _target->_prevelement;
	user *next = _target->_nextelement;
	if(prev)
		prev->_nextelement = next;
	if(next)
		next->_prevelement = prev;
	if(_target == this->head())
		this->_head = next;
	if(_target == this->tail())
	delete _target;
}
//==============================================================================
template < >
void list<book>::edit(int bookid, std::string afname, std::string alname, std::string title, std::string genre, int cnt)
{
	book *_target = this->at(bookid);
	_target->_authorfname = afname;
	_target->_authorlname = alname;
	_target->_title = title;
	_target->_genre = genre;
	_target->_cnt = cnt;
}
//==============================================================================
template < >
void list<user>::edit(int userid, std::string ufname, std::string ulname)
{
	user *_target=this->at(userid);
	_target->_userfname = ufname;
	_target->_userlname = ulname;
}
//==============================================================================
template < >
book* list<book>::at(int id)
{
	book *_current = this->head();
	book *_target = nullptr;
	do
	{
		if(_current->bookid() == id)
		{
			_target = _current;
		}
		_current = _current->_nextelement;
	}
	while(_current);
	if(_target == nullptr)
		throw new std::out_of_range("element not found on the list!\n");
	return _target;
}
template < >
user* list<user>::at(int id)
{
	user *_current = this->head();
	user *_target = nullptr;
	do
	{
		if(_current->userid() == id)
		{
			_target = _current;
		}
		_current = _current->_nextelement;
	}
	while(_current);
	while(_current);
	if(_target == nullptr)
		throw new std::out_of_range("element not found on the list!\n");
	return _target;
}