#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include"consts.h"

using namespace sf;
using namespace std;

View _view;

void vvivodPos()
{
	cout << "_view.pos = " << _view.getCenter().x << " " << _view.getCenter().y << endl;
	//return _view.getCenter();
}

void my_setViewPosition(Vector2f pos)
{
	//Vector2f _pos = pos;
	///*vvivodPos();
	//cout << "pos " << pos.x << " " << pos.y << endl;*/
	//if (pos.x <= (windowWidth / 2 - 48))
	//{
	//	//cout << "true 1" << endl;
	//	_pos.x = windowWidth / 2 - 48;
	//}
	//if (pos.y <= (windowHeight / 2 - 48))
	//{
	//	//cout << "true 2" << endl;
	//	_pos.y = windowHeight / 2 - 48;
	//}
	//if (pos.x >= (1280 - 320 - 48))
	//{
	//	//cout << "true 3" << endl;
	//	_pos.x = 1280 - 320 - 48;
	//}
	//if (pos.y >= (800 - 240 - 48))
	//{
	//	//cout << "true 4" << endl;
	//	_pos.y = 800 - 240 - 48;
	//}
	//_pos.x = _pos.x + 48;
	//_pos.y = _pos.y + 48;
	_view.setCenter(pos);
}

void changeview() {
	if (Keyboard::isKeyPressed(Keyboard::U)) {
		_view.zoom(1.1000); //масштабируем, уменьшение
							//view.zoom(1.0006f); //тоже самое помедленнее соответственно
		cout << "ch view" << endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::I)) {
		_view.zoom(0.9000); //масштабируем, уменьшение
							//view.zoom(1.0006f); //тоже самое помедленнее соответственно
		cout << "ch view" << endl;
	}
}