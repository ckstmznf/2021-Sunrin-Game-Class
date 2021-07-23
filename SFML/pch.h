#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include <vector>	//vectore는 list보다 원소를 순회하는데 빠르지만 원소를 추가 / 삭제 하는것은 느리다.
#include <map>	//map은 key와 value가 있는 kotlin의 그것이다.
#include <random> //랜덤

using namespace std;


using Vector2 = sf::Vector2f; //Vector2f를 Vector2로 바꾸어 사용한다.
using MouseButton = sf::Mouse::Button;
using Key = sf::Keyboard::Key;


const int GAME_WIDTH = 400;
const int GAME_HEIGHT = 600;


const sf::FloatRect GAME_RECT(0, 0, GAME_WIDTH, GAME_HEIGHT);


enum Team {
	ALLY,
	ENEMY,
};

float random(float from, float to);