#include "stdafx.h"
#include "list.h"
#include "user.h"
#include "book.h"
#include "exceptions.h"

template<class T>
list<T>::list()
{
	throw new InvalidListTypeException;
}

template< >
list<user>::list()
{
	this->head = nullptr;
	this->tail = this->head;
}

template< >
list<book>::list()
{
	this->head = nullptr;
	this->tail = this->head;
}

template< >
list<book>::~list()
{
	book *_current = this->head;
	book *_next = _current->_nextbook;
	while(_current->_nextbook)
	{
		delete _current;
		_current = _next;
		_next = _current->_nextbook;
	}
}

template< >
list<user>::~list()
{
	user *_current = this->head;
	user *_next = _current->_nextuser;
	while(_current->_nextuser)
	{
		delete _current;
		_current = _next;
		_next = _current->_nextuser;
	}
}

template< >
void list<user>::push(user *obj)
{
	if(this->head = nullptr)
	{
		this->head = obj;
		this->tail = this->head;
	}
	else
	{
		this->tail->_nextuser = obj;
	}
}

template< >
void list<book>::push(book *obj)
{
	if(this->head = nullptr)
	{
		this->head = obj;
		this->tail = this->head;
	}
	else
	{
		this->tail->_nextbook = obj;
	}
}