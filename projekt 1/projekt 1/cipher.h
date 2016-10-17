#pragma once
#include "stdafx.h"

using namespace std;

class cipher
{
	private:
	public:
	void encode(ifstream*, ofstream*);
	void decode(ifstream*, ofstream*);
	cipher(const char[100]);
	~cipher();
};