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
	while(_current)
	{
		user *tmp = _current;
		_current = _current->_nextuser;
		delete tmp;
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
		obj->_prevuser = this->tail;
		this->tail = obj;
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
		obj->_prevbook = this->tail;
		this->tail = obj;
	}
}
//==============================================================================