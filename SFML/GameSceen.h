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
    list<Bullet*> bulletList; //총알이 담긴다.
    list<Unit*> unitList; //모든 유닛이 담긴다.


    ScrollingBackground* scrollingBackground;

    //적 생성 딜레이
    float spawnDelay;
    float spawnDelayOrigin;
};

