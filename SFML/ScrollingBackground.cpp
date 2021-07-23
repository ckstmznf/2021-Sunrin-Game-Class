#include "pch.h"
#include "ScrollingBackground.h"

ScrollingBackground::ScrollingBackground()
	:speed(200)
{
	bg1 = new Sprite("image/bg.png");
	bg2 = new Sprite("image/bg.png");

	addChild(bg1);
	addChild(bg2);

	bg1->Pos = Vector2(-50, 0);
	bg2->Pos = Vector2(-50, -bg2->rect.height);
}

void ScrollingBackground::update(float dt)
{
	GameObject::update(dt);

	bg1->Pos.y += speed * dt;
	bg2->Pos.y += speed * dt;


	if (bg1->Pos.y > GAME_HEIGHT) {
		bg1->Pos.y = bg2->Pos.y - bg1->rect.height;
	}

	if (bg2->Pos.y > GAME_HEIGHT) {
		bg2->Pos.y = bg1->Pos.y - bg2->rect.height;
	}
}
