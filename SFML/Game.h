#pragma once
#include "GameSceen.h"


class Game
{
public:
	Game();
	void init(sf::Window* window);
	void updata(float dt);
	void render(sf::RenderWindow& window);
	void release();

	GameSceen* currentScene; //���� ȭ��

	sf::FloatRect rect;
};


extern Game game;
//���� ���Ͽ��� ���� ������ ���� ������ ������ش�.