#pragma once
#include "unit.h"
#include "consts.h"
#include "map.h"

class Player : public Unity
{
private:

public:
	Player(RenderWindow &window2D ,String name, Vector2i unitSize, Vector2f pos , UnitSignature unitSignature);
	void move(RenderWindow &window);
};