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

	GameSceen* currentScene; //현재 화면

	sf::FloatRect rect;
};


extern Game game;
//여러 파일에서 접근 가능한 전역 변수로 만들어준다.