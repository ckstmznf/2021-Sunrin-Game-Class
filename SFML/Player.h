#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Unit.h"


class Player :
    public Unit
{
public:
    Player();
    void update(float dt);
    Animation* idle;

    

    //Unit이랑 합침
    //float speed;
    //float fireDelay; //총알의 수
    //float fireDelatOrigin; //총알이 발사될 시간 간격
};

