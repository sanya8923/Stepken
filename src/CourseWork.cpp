// CourseWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ncurses.h>

#include "lib/screen.h"
#include "lib/game.h"

using namespace std;
int main()
{
    Game game;
    game.start_game();

    return 0;
}

