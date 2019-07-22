#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
#include"map.h"
#include"Map3D.h"
#include"Enemy.h"
#include"consts.h"
#include"player.h"
#include "vector"

using namespace std;
using namespace sf;

class HandleGame
{
private:
	Map _map;
	Map3D _map3D;
	vector<Enemy> _enemies;
	Player _player;
	RenderWindow _window2D;
	RenderWindow _window3D;
	Event _event;

public:

	HandleGame();
	void initGame();

	void HGHC(Vector2f &dPos);


	void initUnitFromMap(const vector<pair<Vector2i, UnitSignature>> &units);

	void putUnitOnMap();
	void removeUnitFromMap();

	void moveBots();

	void game();
	~HandleGame();
};

