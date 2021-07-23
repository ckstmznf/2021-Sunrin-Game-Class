#include "pch.h"
#include "Enemy.h"
#include "Game.h"

Enemy::Enemy()
	:Unit(ENEMY, 5, 100, 1)
{
	idle = new Animation("image/enemy-medium/", 2, 10);

	addChild(idle);
	rect = idle->rect;
}


/*Enemy::~Enemy()
{
	//cout << "�� ����" << endl;
}*/

void Enemy::update(float dt)
{
	GameObject::update(dt);

	//������ �̵�ó��
	Pos.y += speed * dt;


	fireDelay += dt;
	if (fireDelay > fireDelayOrigin) {
		
		game.currentScene->addBullet(team, center());
		fireDelay = 0;
	}


}
