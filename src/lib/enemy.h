#pragma once
#include <iostream>
#include "character.h"

using namespace std;

class Enemy: public Character{
    protected:
        int health;
    public:
        Enemy();
        virtual ~Enemy();
        int target();
        int attack_target();
        int defense_target();
        virtual string screen_characters() = 0;
        
};