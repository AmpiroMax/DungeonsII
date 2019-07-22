#pragma once
#include "unit.h"

class Enemy :
	public Unity
{
public:
	Enemy(RenderWindow &window2D ,String name, Vector2i unitSize, Vector2f pos , UnitSignature unitSignature);
	void move(Vector2f& dPos);
	~Enemy();
};