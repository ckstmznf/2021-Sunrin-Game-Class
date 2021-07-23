#include "pch.h"
#include "GameObject.h"


GameObject::GameObject()
	: removeing(false),
	parent(nullptr),
	Pos(0, 0),
	scale(1,1),
	rotation(0),
	rect(0,0,0,0)
{

}

GameObject::~GameObject() {
	for (GameObject* child : children) {
		delete child;
	} // 모든 자식들을 소멸시킨다.
}


void GameObject::addChild(GameObject* child) {
	child->parent = this;
	children.push_back(child);
}

void GameObject::remoceChild(GameObject* child) {
	child->removeing = true;
}

void GameObject::update(float dt) {
	for (GameObject* child : children) {
		child->update(dt);
	} //헤드 하나만 업데이트를 시켜주면 모든 자식에 업데이트를 시켜준다.

	list<GameObject*>::iterator iter = children.begin();
	while (iter != children.end()) {
		if ((*iter)->removeing) {
			delete* iter;
			iter = children.erase(iter);
			// 삭제한뒤 다음 이터를 가져온다. 굳이 ++은 하지 않는다.
		}
		else {
			iter++;
		}
	}
}


void GameObject::render(sf::RenderWindow& window) {
	sf::Transform tmp;
	tmp.rotate(rotation);
	tmp.translate(Pos);
	tmp.scale(scale);
	renderTrandform = tmp;

	if (parent) {
		renderTrandform.combine(parent->renderTrandform);
	}

	for (GameObject* child : children) {
		child->render(window);
	}
}

Vector2 GameObject::center()
{
	return Pos + Vector2(rect.width / 2.f, rect.height / 2.f);
}

void GameObject::setCenter(Vector2 pos)
{
	this->Pos = pos - Vector2(rect.width / 2.f, rect.height / 2.f);
}

sf::FloatRect GameObject::rectWithPos()
{
	//rect + Pos;
	return sf::FloatRect(rect.left + Pos.x, rect.top + Pos.y, rect.width, rect.height);
}
