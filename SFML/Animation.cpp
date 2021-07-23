#include "pch.h"
#include "Animation.h"
#include "Asset.h"

Animation::Animation(const string& path, int frame, int fps, bool loop)
	: frame(frame), fps(fps), loop(loop), currentFraem(0)
{
	for (int i = 0; i < frame; i++) {
		//�ش� ����� �̹������� 0���� ������ ������ �����ͼ� textures�� �߰��Ѵ�.
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
		//���� �������� ��ü ������ ���� Ŭ ��
		if (loop) {
			//�ݺ��� ����ߴٸ� -> ó�� ���������� �̵��Ѵ�.
			currentFraem = 0;
		}
		else {
			//�ݺ��� ����������� -> ������ ���������� ���� ��Ų��.
			currentFraem = frame - 1;
		}
	}

	sprite.setTexture(*textures[(int)currentFraem]); //
}
