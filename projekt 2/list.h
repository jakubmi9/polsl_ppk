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
	list();
	~list();
	/// <summary>Prints contents of the list to the screen</summary>
	void print();
	/// <summary>Alternative print method; to be specialized</summary>
	void print(std::string irrelevant);
	/// <summary>Adds new book to the end of the list.</summary>
	/// <param name="obj">Pointer to the book that'll be added to the list.</param>
	void push(T *obj);
};
//==============================================================================