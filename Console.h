#pragma once
#include"Board.h"

class Console{
	void SetColor(int text, int bg);
	bool Selected;
public:
	Console();
	void print(Board& br);
	char GetShablon2(short& x, short& y, short& a, short& b);
};

