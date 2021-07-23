#include "pch.h"
#include "Player.h"
#include "Input.h"
#include "Game.h"
#include "Unit.h"


Player::Player()
	: Unit(ALLY, 10, 300, 0.1)
{
	idle = new Animation("image/player", 2, 10, true);
	addChild(idle);
	rect = idle->rect;
}

void Player::update(float dt)
{
	GameObject::update(dt);
	
	//플레이어 이동 처리
	{
		if (Input::getKey(Key::Up)) {
			Pos.y -= speed * dt;
		}
		else if (Input::getKey(Key::Down)) {
			Pos.y += speed * dt;
		}
		if (Input::getKey(Key::Left)) {
			Pos.x -= speed * dt;
		}
		else if (Input::getKey(Key::Right)) {
			Pos.x += speed * dt;
		}
	}
	
	//플레이어 위치 고정
	{
		if (Pos.y < 0) {
			Pos.y = 0;
		}
		else if (Pos.y > GAME_HEIGHT - rect.height) {
			Pos.y = GAME_HEIGHT - rect.height;
		}
		if (Pos.x < 0) {
			Pos.x = 0;
		}
		else if (Pos.x > GAME_WIDTH - rect.width) {
			Pos.x = GAME_WIDTH - rect.width;
		}
	}




	//cout << fireDelay << endl;
	if (fireDelay > fireDelayOrigin) {
		if (Input::getKey(Key::Z)) {
			fireDelay = 0;


			//Vector2 p = Vector2(Pos.x + rect.width / 2, Pos.y);
			game.currentScene->addBullet(team, center());
		}
	}
	else if (fireDelay <= fireDelayOrigin) {
		fireDelay += dt;
	}

}
