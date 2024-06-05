#pragma once
#include <ctime>
#include <utility>


class Board{
public:
	char** count;

	Board();
	~Board();
	void CreateBoard();
	bool CheckBox(const size_t& x, const size_t& y, char& ch);
	char GetBox(const size_t& x, const size_t& y);
	bool recursive();
	std::pair<int, int> findEmpty();
	void createCown();
};

