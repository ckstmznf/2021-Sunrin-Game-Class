#pragma once
#include "Sprite.h"
class Animation :
    public Sprite
{
public:
    Animation(const string& path, int frame, int fps, bool loop = true);


    int frame; //프레임의 수
    float fps; // 1초에 나오는 프레임 수
    bool loop; // 이 에니메이션이 반복을 하는지 
    vector<sf::Texture*> textures; //애니메이션의 프레임들
    // vector은 list와 비슷하지만 인덱싱이 가능하다.

    float currentFraem;

    void update(float dt);
    

};

