#pragma once
#ifndef LIST_H
#define LIST_H
//==============================================================================
/// <summary>template class for bidirectional list of elements. Only book and user are supported as a element type ATM.</summary>
template<class T>
class list
{
	private:
	int _length = 0;
	T *_head = nullptr;
	T *_tail = nullptr;
	public:
	list()
	{
		this->_head = nullptr;
		this->_tail = this->_head;
	}
	~list()
	{
		T *_current = this->_head;
		while(_current)
		{
			T *tmp = _current;
			_current = _current->_nextelement;
			delete tmp;
		}
	}
	/// <summary>Prints contents of the list to the screen</summary>
	void print();
	/// <summary>Alternative print method; to be specialized</summary>
	void print(std::string irrelevant);
	/// <summary>TBD</summary>
	void print(std::string modeswitch, std::string query);
	/// <summary>Adds new book to the end of the list.</summary>
	/// <param name="obj">Pointer to the book that'll be added to the list.</param>
	void push(T *obj)
	{
		if(this->_head == nullptr)
		{
			this->_head = obj;
			this->_tail = obj;
			this->_length++;
		}
		else
		{
			this->_tail->_nextelement = obj;
			obj->_prevelement = this->_tail;
			this->_tail = obj;
			this->_length++;
		}
	}
	///
	void remove(int id);
	/// <summary>Returns the length of the list as integer value</summary>
	int length()
	{
		return this->_length;
	}
	/// <summary>Returns a pointer to the first object in the list.</summary>
	T* head()
	{
		return this->_head;
	}
	/// <summary>Returns a pointer to the last object in the list.</summary>
	T* tail()
	{
		return this->_tail;
	}
};
//==============================================================================
#endif // !LIST_H