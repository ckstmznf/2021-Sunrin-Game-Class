#pragma once
#include "Scene.h"
#include "GameSceen.h"
#include "input.h"
#include "Player.h"
#include "Bullet.h"
#include "ScrollingBackground.h"
#include "Unit.h"
class GameSceen :
    public Scene
{
public:
    GameSceen();

    void update(float dt);
    void addBullet(Team team, Vector2 pos);
    void addEnemy();


    Player* player;
    list<Bullet*> bulletList; //�Ѿ��� ����.
    list<Unit*> unitList; //��� ������ ����.


    ScrollingBackground* scrollingBackground;

    //�� ���� ������
    float spawnDelay;
    float spawnDelayOrigin;
};

