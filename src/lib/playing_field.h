#pragma once
#include <iostream>
#include "character.h"
#include "enemy.h"
#include "invader.h"

using namespace std;

class Playing_field{
    private:

    public:
        Playing_field();
        virtual ~Playing_field();
    
        string welcome_field();
        string event_field(string question, string hero_health, string enemy_hearth, Enemy &enemy);
        string health_to_str(Character &ch);
        string health_board(string hero_health, string enemy_hearth);
        string logo();
        string line();
        string screen_characters(Enemy &enemy);
        string screen_you_win();
        string screen_you_lose();
        string plug(string res);
        
};