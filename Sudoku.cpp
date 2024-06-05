#include <iostream>
#include"Board.h"
#include"Console.h"

int main()
{
    Board Br;
    Console Cs;
    Cs.print(Br);
    Br.CreateBoard();
    Cs.print(Br);
}
