#pragma once
#include "pch.h"
class Input
{
public:
	static void test(); //Input��ü�� �������� �ʰ� test()�Լ��� ����� �� �ִ�.
	
	static bool getMouseButton(MouseButton button); //������ �����ְ� ���ݵ� �����ְ� ��� �����ִٸ� true��ȯ
	static bool getMouseButtonDown(MouseButton button); //���ݸ� �����ִٸ� true ��ȯ
	static bool getMouseButtonUp(MouseButton button); //��� �����ִٰ� ���� ���ٸ� true��ȯ
	static void update(float dt); //���콺 ��ư Ŭ���� ������Ʈ �Ѵ�.
	static Vector2 getMousePostion();

	static bool getKey(Key key);
	static bool getKeyDown(Key key);
	static bool getKeyUp(Key key);

	static bool AnyKey(); //�ƹ�Ű�� �������� true

	static bool lastMouseButton[MouseButton::ButtonCount]; //���� �����ӿ� ���콺 ��ư�� ���ȴ����� ���콺��ư ������ŭ �����Ѵ�.
	static bool currentMouseButton[MouseButton::ButtonCount]; //���� �����ӿ� ���콺 ��ư�� ���ȴ���
	static bool lastKey[Key::KeyCount];
	static bool currentKey[Key::KeyCount];
	//�����ִٸ� true, �ƴ϶�� false


	static sf::Window* window;
};
