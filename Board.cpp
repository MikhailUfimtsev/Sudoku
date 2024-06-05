#include "Board.h"
#include <stdlib.h>
#include <utility>
#pragma warning(disable:4244)


Board::Board(){
	count = new char* [9];
	for (size_t i = 0; i < 9; i++){
		count[i] = new char[9];
	}
	for (size_t i = 0; i < 9; i++) {
		for (size_t j = 0; j < 9; j++) {
			count[i][j] = '.';
		}
	}
	srand(time(0));
}

Board::~Board(){
	for (size_t i = 0; i < 9; i++)
		delete [] count[i];
	delete[] count;
}

void Board::CreateBoard(){
	createCown();
	recursive();
	int x = 0, y = 0;
	for (size_t i = 0; i < 49; i++) {
		x = rand() % 9;
		y = rand() % 9;
		if (count[x][y] == '.') i--;
		count[x][y] = '.';
	}
}

bool Board::CheckBox(const size_t& x, const size_t& y, char& ch){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((x % 3 != i && y % 3 != j) && count[(x/3) * 3 + i][(y/3) * 3 + j] == ch) return false;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != x && count[i][y] == ch) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (i != y && count[x][i] == ch) return false;
	}
	return true;
}

char Board::GetBox(const size_t& x, const size_t& y)
{
	return count[x][y];
}

bool Board::recursive()
{
	auto pos = findEmpty();
	if (pos.first == -1 && pos.second == -1) return true;
	for (char c = 49; c < 58; c++){
		if (CheckBox(pos.first, pos.second, c)) {
			count[pos.first][pos.second] = c;
			if (recursive()) return true;
			count[pos.first][pos.second] = '.';
		}
	}
	return false;
}

std::pair<int, int> Board::findEmpty()
{
	std::pair<int, int> tmp ;
	tmp.first = -1; tmp.second = -1;
	for (size_t i = 0; i < 9; i++) {
		for (size_t j = 0; j < 9; j++) {
			if (count[i][j] == '.') {
				tmp.first = i;
				tmp.second = j;
				return tmp;
			}
		}
	}
	tmp.first = -1; tmp.second = -1;
	return tmp;
}

void Board::createCown(){
	char ch;
	bool k;
	for (size_t i = 0; i < 9; i++) {
		k = true;
		while (k){
			ch = rand() % 9 + 49;
			if (CheckBox(0, i, ch)) { 
				count[0][i] = ch; 
				k = !k;
			}
		}
	}
}
