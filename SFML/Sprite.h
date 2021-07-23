#pragma once
#include "GameObject.h"


class Sprite :
    public GameObject
{
public:
    Sprite();
    Sprite(const string& path);



    sf::Texture* texture; //�̹��� ������ �ҷ� �� �� �ִ� �׸���
    sf::Sprite sprite; // �ؽ����� �ǿ� �׸��� ������.


    void update(float dt);
    void render(sf::RenderWindow& window);
};

