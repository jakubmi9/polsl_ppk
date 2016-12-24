#pragma once
//==============================================================================
template<class T>
class list
{
	public:
	T *head = nullptr, *tail = nullptr;
	list();
	~list();
	void push(T *obj);
};
//==============================================================================