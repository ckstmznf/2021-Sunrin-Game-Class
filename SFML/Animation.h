#pragma once
#include "Sprite.h"
class Animation :
    public Sprite
{
public:
    Animation(const string& path, int frame, int fps, bool loop = true);


    int frame; //�������� ��
    float fps; // 1�ʿ� ������ ������ ��
    bool loop; // �� ���ϸ��̼��� �ݺ��� �ϴ��� 
    vector<sf::Texture*> textures; //�ִϸ��̼��� �����ӵ�
    // vector�� list�� ��������� �ε����� �����ϴ�.

    float currentFraem;

    void update(float dt);
    

};

