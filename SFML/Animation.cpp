#include "pch.h"
#include "Animation.h"
#include "Asset.h"

Animation::Animation(const string& path, int frame, int fps, bool loop)
	: frame(frame), fps(fps), loop(loop), currentFraem(0)
{
	for (int i = 0; i < frame; i++) {
		//해당 경로의 이미지들을 0부터 프레임 수까지 가져와서 textures에 추가한다.
		sf::Texture* t;
		t = asset.getTexture(path + "/" + to_string(i) + ".png");
		textures.push_back(t);
		//t.loadFromFile(path + "/" + to_string(i) + ".png");

	}

	sprite.setTexture(*textures[0]);
	rect = sprite.getGlobalBounds();
}

void Animation::update(float dt)
{
	Sprite::update(dt);
	currentFraem += fps * dt;

	if ((int)currentFraem >= frame) {
		//현재 프레임이 전체 프레임 보다 클 때
		if (loop) {
			//반복을 허용했다면 -> 처음 프레임으로 이동한다.
			currentFraem = 0;
		}
		else {
			//반복을 비허용했을때 -> 마지막 프레임으로 고정 시킨다.
			currentFraem = frame - 1;
		}
	}

	sprite.setTexture(*textures[(int)currentFraem]); //
}
