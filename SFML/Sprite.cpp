#include "pch.h"
#include "Sprite.h"
#include "Asset.h"

Sprite::Sprite()
{

}

Sprite::Sprite(const string& path) {
	texture = asset.getTexture(path);
	//texture.loadFromFile(path); //이미지를 불러오고
	sprite.setTexture(*texture);  //불러온 이미지를그린다

	rect = sprite.getGlobalBounds(); //이미지 크기를 가져온다.
}

void Sprite::update(float dt)
{

}

void Sprite::render(sf::RenderWindow& window) {
	//이미지를 윈도우 창에 그리기 위해 RenderWindow(main에서 만든)를 가져온다.
	GameObject::render(window); // Sprite의 자식들을 render시킨다.

	sf::RenderStates states(renderTrandform);

	window.draw(sprite, states); //만든 sprite를 윈도우 창에 그린다.
}