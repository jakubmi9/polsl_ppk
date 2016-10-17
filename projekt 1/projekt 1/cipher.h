#pragma once
#include "stdafx.h"

using namespace std;

class cipher
{
	private:
	bool tableopened = 0;
	public:
	void encode(ifstream*, ofstream*);
	void decode(ifstream*, ofstream*);
	cipher(const char[100]);
	~cipher();
};