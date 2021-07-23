#include "pch.h"
#include "Sprite.h"
#include "GameSceen.h"
#include <Windows.h>
#include "ScrollingBackground.h"
#include "Enemy.h"

extern bool GAME_END;

GameSceen::GameSceen()
	:spawnDelay(0),
	spawnDelayOrigin(1.5)
{
	/*Sprite* sprite = new Sprite("image/test.png");
	addChild(sprite);

	sprite->Pos = Vector2(100, 100);
	sprite->scale = Vector2(0.5, 0.5);
	sprite->rotation = 10;*/


	scrollingBackground = new ScrollingBackground();
	addChild(scrollingBackground);

	player = new Player(); //요소 하나를 만든다.
	//player->Pos = Vector2(GAME_WIDTH / 2 - player->rect.width / 2, player->rect.height * 10); //플레이어를 화면 가운데로 이동
	player->setCenter(Vector2(GAME_WIDTH / 2.f, 400));
	addChild(player); //요소 하나를 GameObject에 자식으로 추가한다 (= 화면에 보여준다.)
	unitList.push_back(player);
}

void GameSceen::update(float dt)
{
	Scene::update(dt);

	/*
		if (Input::getMouseButtonDown(MouseButton::Left)) {
			cout << "마우스 클릭" << endl;
		}
		else if(Input::getMouseButtonUp(MouseButton::Right)) {
			cout << "마우스 클릭 해제" << endl;
		}
		else if (Input::getMouseButton(MouseButton::Left)) {
			cout << "마우스 클릭 중" << endl;
		}

		if (Input::getKeyDown(Key::Space)) {
			cout << "스페이스바 클릭" << endl;
		}
		else if (Input::getKey(Key::Space)) {
			(player->Pos).y += 1;
			cout << (player->Pos).y << endl;
			//y += 10;
			//player->Pos = Vector2(0, y);
			cout << "스페이스바 클릭 중" << endl;
		}
		else if (Input::getKeyUp(Key::Space)) {
			cout << "스페이스바 클릭 해제" << endl;
		}
	*/

	list<Bullet*>::iterator bIter = bulletList.begin();

	//총알 삭제
	while (bIter != bulletList.end()) {
		Bullet* b = *bIter;

		bool bulletRemoving = false;

		bulletRemoving = !b->rectWithPos().intersects(GAME_RECT);

		for (Unit* u : unitList) {
			if (b->team == u->team) {
				//총알의 팀과 유닛의 팀이 같다.
				continue;
			}

			if (b->rectWithPos().intersects(u->rectWithPos())) {
				//총알과 유닛이 충돌했다.
				u->decreaseHp();
				bulletRemoving = true;
				break;
			}
		}

		if (bulletRemoving) {
			//intersects() 두 사각형의 충돌했다.
			remoceChild(b);
			bIter = bulletList.erase(bIter);
			//delete b;
		}
		else {
			bIter++;
		}
	}

	//총알과 유닛의 충돌 처리
	list<Unit*>::iterator uIter = unitList.begin();
	while (uIter != unitList.end()) {
		Unit* u = *uIter;

		if (u->die || u->Pos.y > GAME_HEIGHT) {
			remoceChild(u);
			uIter = unitList.erase(uIter);
		}
		else {
			uIter++;
		}
	}

	spawnDelay += dt;
	if (spawnDelay > spawnDelayOrigin) {
		spawnDelay = 0;
		addEnemy();
	}


	//플레이어가 사망했을때 게임을 종료시킨다.
	if (player->die) {
		GAME_END = true;
	}
}

void GameSceen::addBullet(Team team, Vector2 pos)
{
	Bullet* b = new Bullet(team);
	addChild(b);	

	bulletList.push_back(b);

	//Vector2 p = Vector2(pos.x + player->rect.width / 2 - b->rect.width / 2, pos.y - 10);
	b->setCenter(pos);
}

void GameSceen::addEnemy()
{
	Enemy* e = new Enemy();
	e->setCenter(Vector2(random(50, GAME_WIDTH - 50), -50)); //랜덤한 값에서 적이 생성
	addChild(e);
	unitList.push_back(e);
}
