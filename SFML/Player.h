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

    

    //Unit�̶� ��ħ
    //float speed;
    //float fireDelay; //�Ѿ��� ��
    //float fireDelatOrigin; //�Ѿ��� �߻�� �ð� ����
};

