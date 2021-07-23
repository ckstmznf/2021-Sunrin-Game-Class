#pragma once
#include "GameObject.h"
#include "Sprite.h"

class ScrollingBackground :
    public GameObject
{
public:
    ScrollingBackground();

    void update(float dt);

    Sprite* bg1;
    Sprite* bg2;

    float speed; //����� ������ �ӵ�
};

