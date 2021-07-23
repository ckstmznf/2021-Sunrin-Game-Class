#pragma once
#include "pch.h"
class Input
{
public:
	static void test(); //Input객체에 접근하지 않고 test()함수를 사용할 수 있다.
	
	static bool getMouseButton(MouseButton button); //이전에 눌려있고 지금도 눌려있고 계속 눌려있다면 true반환
	static bool getMouseButtonDown(MouseButton button); //지금만 눌려있다면 true 반환
	static bool getMouseButtonUp(MouseButton button); //계속 눌려있다가 지금 땠다면 true반환
	static void update(float dt); //마우스 버튼 클릭을 업데이트 한다.
	static Vector2 getMousePostion();

	static bool getKey(Key key);
	static bool getKeyDown(Key key);
	static bool getKeyUp(Key key);

	static bool AnyKey(); //아무키나 눌렀을때 true

	static bool lastMouseButton[MouseButton::ButtonCount]; //이전 프레임에 마우스 버튼이 눌렸는지를 마우스버튼 개수만큼 저장한다.
	static bool currentMouseButton[MouseButton::ButtonCount]; //현재 프레임에 마우스 버튼이 눌렸는지
	static bool lastKey[Key::KeyCount];
	static bool currentKey[Key::KeyCount];
	//눌려있다면 true, 아니라면 false


	static sf::Window* window;
};
