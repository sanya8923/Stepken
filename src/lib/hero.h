#pragma once
#include <iostream>

#include "character.h"

using namespace std;

class Hero: public Character{
    private:
        int health;

    public:
        Hero();
        virtual ~Hero();

};