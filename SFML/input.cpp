#include "pch.h"
#include "Input.h"


sf::Window* Input::window = nullptr;
bool Input::lastMouseButton[MouseButton::ButtonCount] = { 0 };
bool Input::currentMouseButton[MouseButton::ButtonCount] = { 0 };

bool Input::lastKey[Key::KeyCount] = { 0 };
bool Input::currentKey[Key::KeyCount] = { 0 };


bool Input::getMouseButton(MouseButton button)
{
    return lastMouseButton[button] && currentMouseButton[button];
    //이전에 눌렸고 지금도 눌려있다.
}

bool Input::getMouseButtonDown(MouseButton button)
{
    return !lastMouseButton[button] && currentMouseButton[button];
}

bool Input::getMouseButtonUp(MouseButton button)
{
    return lastMouseButton[button] && !currentMouseButton[button];
}

void Input::update(float dt)
{
    for (int i = 0; i < sf::Mouse::ButtonCount; i++) {
        lastMouseButton[i] = currentMouseButton[i];
        currentMouseButton[i] = sf::Mouse::isButtonPressed(MouseButton(i));
    }

    for (int i = 0; i < Key::KeyCount; i++) {
        lastKey[i] = currentKey[i];
        currentKey[i] = sf::Keyboard::isKeyPressed(Key(i));
    }
}

Vector2 Input::getMousePostion()
{
    return Vector2(sf::Mouse::getPosition(*window));
}

bool Input::getKey(Key key)
{
    return lastKey[key] && currentKey[key];
}

bool Input::getKeyDown(Key key)
{
    return !lastKey[key] && currentKey[key];
}

bool Input::getKeyUp(Key key)
{
    return lastKey[key] && !currentKey[key];
}

bool Input::AnyKey()
{
    for (int i = 0; i < Key::KeyCount; i++) {
        if (currentKey[i]) {
            return currentKey[i];
        }
    }
    return false;
}
