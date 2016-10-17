#pragma once
#include "stdafx.h"

using namespace std;

class cipher
{
	private:
	public:
	void encode(ifstream*);
	void decode(ifstream*);
	cipher(const char[100]);
	~cipher();
};