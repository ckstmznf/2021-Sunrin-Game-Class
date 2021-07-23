#pragma once
#include "Unit.h"
#include "Animation.h"

class Enemy :
    public Unit
{
public:
    Enemy();
    ~Enemy();

    void update(float dt);
    
    Animation* idle;
};

