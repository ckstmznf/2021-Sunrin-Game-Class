#include "pch.h"
#include "Sprite.h"
#include "Asset.h"

Sprite::Sprite()
{

}

Sprite::Sprite(const string& path) {
	texture = asset.getTexture(path);
	//texture.loadFromFile(path); //�̹����� �ҷ�����
	sprite.setTexture(*texture);  //�ҷ��� �̹������׸���

	rect = sprite.getGlobalBounds(); //�̹��� ũ�⸦ �����´�.
}

void Sprite::update(float dt)
{

}

void Sprite::render(sf::RenderWindow& window) {
	//�̹����� ������ â�� �׸��� ���� RenderWindow(main���� ����)�� �����´�.
	GameObject::render(window); // Sprite�� �ڽĵ��� render��Ų��.

	sf::RenderStates states(renderTrandform);

	window.draw(sprite, states); //���� sprite�� ������ â�� �׸���.
}