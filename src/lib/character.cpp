#include <iostream>
#include "character.h"

using namespace std;

//public

Character::Character(){
    this->health = health;
    this->power = power;
}
Character::~Character(){

}
int Character::get_health(){
    return health;
}
void Character::set_health(int target_attack, int target_defence){
    if(target_attack == target_defence){
        power = 2;
    }
    health = health - power;
    power = 5;
}
int Character::get_power(){
    return power;
}
void Character::set_power(int defense){
    power = power - defense;
}