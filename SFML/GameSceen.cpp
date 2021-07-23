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

	player = new Player(); //��� �ϳ��� �����.
	//player->Pos = Vector2(GAME_WIDTH / 2 - player->rect.width / 2, player->rect.height * 10); //�÷��̾ ȭ�� ����� �̵�
	player->setCenter(Vector2(GAME_WIDTH / 2.f, 400));
	addChild(player); //��� �ϳ��� GameObject�� �ڽ����� �߰��Ѵ� (= ȭ�鿡 �����ش�.)
	unitList.push_back(player);
}

void GameSceen::update(float dt)
{
	Scene::update(dt);

	/*
		if (Input::getMouseButtonDown(MouseButton::Left)) {
			cout << "���콺 Ŭ��" << endl;
		}
		else if(Input::getMouseButtonUp(MouseButton::Right)) {
			cout << "���콺 Ŭ�� ����" << endl;
		}
		else if (Input::getMouseButton(MouseButton::Left)) {
			cout << "���콺 Ŭ�� ��" << endl;
		}

		if (Input::getKeyDown(Key::Space)) {
			cout << "�����̽��� Ŭ��" << endl;
		}
		else if (Input::getKey(Key::Space)) {
			(player->Pos).y += 1;
			cout << (player->Pos).y << endl;
			//y += 10;
			//player->Pos = Vector2(0, y);
			cout << "�����̽��� Ŭ�� ��" << endl;
		}
		else if (Input::getKeyUp(Key::Space)) {
			cout << "�����̽��� Ŭ�� ����" << endl;
		}
	*/

	list<Bullet*>::iterator bIter = bulletList.begin();

	//�Ѿ� ����
	while (bIter != bulletList.end()) {
		Bullet* b = *bIter;

		bool bulletRemoving = false;

		bulletRemoving = !b->rectWithPos().intersects(GAME_RECT);

		for (Unit* u : unitList) {
			if (b->team == u->team) {
				//�Ѿ��� ���� ������ ���� ����.
				continue;
			}

			if (b->rectWithPos().intersects(u->rectWithPos())) {
				//�Ѿ˰� ������ �浹�ߴ�.
				u->decreaseHp();
				bulletRemoving = true;
				break;
			}
		}

		if (bulletRemoving) {
			//intersects() �� �簢���� �浹�ߴ�.
			remoceChild(b);
			bIter = bulletList.erase(bIter);
			//delete b;
		}
		else {
			bIter++;
		}
	}

	//�Ѿ˰� ������ �浹 ó��
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


	//�÷��̾ ��������� ������ �����Ų��.
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
	e->setCenter(Vector2(random(50, GAME_WIDTH - 50), -50)); //������ ������ ���� ����
	addChild(e);
	unitList.push_back(e);
}
