#pragma once
#include "GameObject.h"


class Sprite :
    public GameObject
{
public:
    Sprite();
    Sprite(const string& path);



    sf::Texture* texture; //이미지 파일을 불러 올 수 있는 그림판
    sf::Sprite sprite; // 텍스쳐의 판에 그림을 입힌다.


    void update(float dt);
    void render(sf::RenderWindow& window);
};

