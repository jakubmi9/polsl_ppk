#include "stdafx.h"
#include "list.h"
#include "user.h"
#include "book.h"
#include "exceptions.h"
//==============================================================================
template<class T>
list<T>::list()
{
	throw new InvalidListTypeException;
}
//==============================================================================
template< >
list<user>::list()
{
	this->head = nullptr;
	this->tail = this->head;
}
//==============================================================================
template< >
list<book>::list()
{
	this->head = nullptr;
	this->tail = this->head;
}
//==============================================================================
template< >
list<book>::~list()
{
	book *_current = this->head;
	while(_current)
	{
		book *tmp = _current;
		_current = _current->_nextbook;
		delete tmp;
	}
}
//==============================================================================
template< >
list<user>::~list()
{
	user *_current = this->head;
	//user *_next = _current->_nextuser ? _current->_nextuser : nullptr;
	while(_current)
	{
		user *tmp = _current->_nextuser ? _current->_nextuser : nullptr;
		delete _current;
		_current = tmp;
		/*_next = _current->_nextuser ? _current->_nextuser : nullptr;*/
	}
}
//==============================================================================
template< >
void list<user>::push(user *obj)
{
	if(this->head == nullptr)
	{
		this->head = obj;
		this->tail = obj;
	}
	else
	{
		this->tail->_nextuser = obj;
	}
}
//==============================================================================
template< >
void list<book>::push(book *obj)
{
	if(this->head == nullptr)
	{
		this->head = obj;
		this->tail = obj;
	}
	else
	{
		this->tail->_nextbook = obj;
	}
}
//==============================================================================