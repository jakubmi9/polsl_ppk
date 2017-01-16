#pragma once
//==============================================================================
/// <summary>template class for bidirectional list of elements. Only book and user are supported as a element type ATM.</summary>
template<class T>
class list
{
	public:
	/// <summary>Pointer to the first object in the list.</summary>
	T *head = nullptr;
	/// <summary>Pointer to the last object in the list.</summary>
	T *tail = nullptr;
	list()
	{
		this->head = nullptr;
		this->tail = this->head;
	}
	~list()
	{
		T *_current = this->head;
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
		if(this->head == nullptr)
		{
			this->head = obj;
			this->tail = obj;
		}
		else
		{
			this->tail->_nextelement = obj;
			obj->_prevelement = this->tail;
			this->tail = obj;
		}
	}
};
//==============================================================================