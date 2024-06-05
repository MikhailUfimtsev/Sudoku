#include "Console.h"
#include<Windows.h>
#include <iostream>
#define WW 9
#define HH 4
#define shiftX 1
#define shiftY 4

short shablon[HH][WW] = { {0,2,2,2,2,2,0},
						  {0,1,0,4,0,1,0},
						  {0,3,3,3,3,3,0} };

void Console::SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

Console::Console(){
	Selected = false;
}

void Console::print(Board& br){
    using namespace std;
    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 9; j++) {
            cout << br.GetBox(i, j);
            ((j + 1) % 3 == 0 && j != 8) ? cout << "|" : cout << " ";
        }cout << endl;
        if ((i + 1) % 3 == 0 && i != 8) {
            for (int j = 0; j < 17; j++) {
                cout << "-";
            }cout << endl;
        }
    }cout << endl << endl;
}

char Console::GetShablon2(short& x, short& y, short& a, short& b){
	switch (shablon[a][b])
	{
	case 0:
		(x * 7 + y) & 1 ? SetColor(8, 15) : SetColor(15, 8);
		return 32;
	case 1:
		(x * 7 + y) & 1 ? SetColor(1, 15) : SetColor(1, 8);
		if (Selected) { return 219; }
		else { return 32; };
	case 2:
		(x * 7 + y) & 1 ? SetColor(1, 15) : SetColor(1, 8);
		if (Selected) { return 220; }
		else { return 32; };
	case 3:
		(x * 7 + y) & 1 ? SetColor(1, 15) : SetColor(1, 8);
		if (Selected) { return 223; }
		else { return 32; };
	}
}




	//short shablon[HH][WW] = { {0,2,2,2,2,2,0},
	//						    {0,1,0,4,0,1,0},
	//						    {0,3,3,3,3,3,0} };
	//					
	//short shablon2[HH][WW] = { {0,2,2,2,2,2,2,2,0},
	//						     {0,1,0,0,0,0,0,1,0},
	//						     {0,1,0,0,0,0,0,1,0},
	//						     {0,3,3,3,3,3,3,3,0} };
	//void SetColor(int text, int background)
	//{
	//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	//}
	//char GetShablon2(short& x, short& y, short& a, short& b) {
	//	switch (shablon2[a][b])
	//	{
	//	case 0:
	//		(x * 7 + y) & 1 ? SetColor(8, 15) : SetColor(15, 8);
	//		return 32;
	//	case 1:
	//		(x * 7 + y) & 1 ? SetColor(1, 15) : SetColor(1, 8);
	//		if (Selected) { return 219; }
	//		else { return 32; };
	//	case 2:
	//		(x * 7 + y) & 1 ? SetColor(1, 15) : SetColor(1, 8);
	//		if (Selected) { return 220; }
	//		else { return 32; };
	//	case 3:
	//		(x * 7 + y) & 1 ? SetColor(1, 15) : SetColor(1, 8);
	//		if (Selected) { return 223; }
	//		else { return 32; };
	//	}
	//}
	//char GetShablon(short& x, short& y, short& a, short& b) {
	//	int col = 6;
	//	if (Selected) col = 1;
	//	switch (shablon[a][b])
	//	{
	//	case 0:
	//		(x * 7 + y) & 1 ? SetColor(8, 15) : SetColor(15, 8);
	//		return 32;
	//	case 1:
	//		(x * 7 + y) & 1 ? SetColor(col, 15) : SetColor(col, 8);
	//		return 219;
	//	case 2:
	//		(x * 7 + y) & 1 ? SetColor(col, 15) : SetColor(col, 8);
	//		return 220;
	//	case 3:
	//		(x * 7 + y) & 1 ? SetColor(col, 15) : SetColor(col, 8);
	//		return 223;
	//	case 4:
	//		color_ ? SetColor(0, 15) : SetColor(15, 0);
	//		return obj;
	//	case 5:
	//		color_ ? SetColor(0, 15) : SetColor(15, 0);
	//		return 32;
	//	}
	//}

	//void print_nullptr(short& x, short& y) {
	//	for (short a = 0; a < HH; a++) {
	//		for (short b = 0; b < WW; b++) {
	//			std::cout << "\033[" << x * HH + a + shiftX + 1 << ";" << y * WW + b + shiftY << "H" << GetShablon2(x, y, a, b);
	//		}
	//	} std::cout << std::endl;
	//	SetColor(15, 0);
	//}