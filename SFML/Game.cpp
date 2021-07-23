#include "pch.h"
#include "Game.h"
#include "Input.h"


Game game; //전역변수 정의

Game::Game()
	:currentScene(nullptr)
{

}

void Game::init(sf::Window* window)
{
	rect = sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT);
	Input::window = window;
	currentScene = new GameSceen();

}

void Game::updata(float dt)
{
	Input::update(dt);
	currentScene->update(dt);
}

void Game::render(sf::RenderWindow& window)
{
	currentScene->render(window);
}

void Game::release()
{
	delete currentScene;
}


