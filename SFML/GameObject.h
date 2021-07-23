#pragma once
#include "pch.h"

// 모든 클래스의 기반 클래스
// updata, render같은걸 처리한다.

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
	Vector2 Pos; // 좌표계
	Vector2 scale;
	float rotation;

	sf::FloatRect rect;
};

