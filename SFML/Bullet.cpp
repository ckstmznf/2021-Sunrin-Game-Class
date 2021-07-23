#include "pch.h"
#include "Bullet.h"
#include "Animation.h"

Bullet::Bullet(Team team)
	: team(team),
	speed(800)
{
	Animation* a;
	if (team == ALLY) {
		a = new Animation("image/bullet/player", 2, 10);
	}
	else {
		a = new Animation("image/bullet/enemy", 2, 10);
	}

	addChild(a);
	rect = a->rect;
}


void Bullet::update(float dt)
{
	GameObject::update(dt);
	
	if (team == ALLY) {
		Pos.y -= speed * dt;
	}
	else {
		Pos.y += speed * dt;
	}
	
}
