#pragma once
#include "pch.h"

// ��� Ŭ������ ��� Ŭ����
// updata, render������ ó���Ѵ�.

class GameObject {
public:
	GameObject();
	virtual ~GameObject();

	GameObject* parent;
	list<GameObject*> children;
	
	bool removeing;

	void addChild(GameObject* child);
	void remoceChild(GameObject* child);
	virtual void update(float dt);
	virtual void render(sf::RenderWindow& window);
	Vector2 center();
	void setCenter(Vector2 pos);

	sf::FloatRect rectWithPos();


	sf::Transform renderTrandform;
	Vector2 Pos; // ��ǥ��
	Vector2 scale;
	float rotation;

	sf::FloatRect rect;
};

