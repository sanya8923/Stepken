#pragma once
#include <iostream>
#include "enemy.h"

using namespace std;

class Dino: public Enemy{
    private:
        int health;
    public:
        Dino();
        virtual ~Dino();
        string screen_characters();
};