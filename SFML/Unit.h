#pragma once
#include "GameObject.h"
class Unit :
    public GameObject
{
public:
    Unit(Team team, int hp, float speed, float fireDelayOrigin);
    
    void decreaseHp();

    Team team;
    int hp, speed;
    float fireDelay;
    float fireDelayOrigin;
    bool die;
};

