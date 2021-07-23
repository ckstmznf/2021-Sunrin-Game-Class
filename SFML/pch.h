#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include <vector>	//vectore�� list���� ���Ҹ� ��ȸ�ϴµ� �������� ���Ҹ� �߰� / ���� �ϴ°��� ������.
#include <map>	//map�� key�� value�� �ִ� kotlin�� �װ��̴�.
#include <random> //����

using namespace std;


using Vector2 = sf::Vector2f; //Vector2f�� Vector2�� �ٲپ� ����Ѵ�.
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