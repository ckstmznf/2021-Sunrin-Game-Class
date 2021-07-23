#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
public:
    Bullet(Team team);

    Team team;
    void update(float dt);
    float speed;
};

