#pragma once
template<class T>
class list
{
	public:
	T *head, *tail;
	list();
	~list();
	void push(T *obj);
};
