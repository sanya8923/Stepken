#pragma once
#include <iostream>

#include "hero.h"
#include "enemy.h"
#include "dino.h"
#include "pacman.h"
#include "invader.h"
#include "screen.h"
#include "playing_field.h"

using namespace std;

class Game{
    private:
        string hero_health;
        string enemy_health;
        int hero_target_attack;
        int hero_target_defense;
        int enemy_target_attack;
        int enemy_target_defense;
        string attack_text = "Where you hit?"; 
        string defense_text = "What will you protect?";
        vector<string> screen_options_new_game = {"New game", "Exit"};
        vector<string> win_screen_options = {"Next round", "Exit"};
        vector<string>choice_target_options = {"Head", "Body", "Legs"};
        int count;
        Playing_field playing_field;
        Playing_field health_screen;
    public:
        Game();
        virtual ~Game();
        void new_event(int choice, Hero &hero, Enemy &enemy, Playing_field &health_screen);
        void start_game();
        void event(Hero &hero, Enemy &enemy, Playing_field &health_screen);
        void win_event(Playing_field &health_screen);
        void game_over();
        void lose_event();
};