#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<iostream>
#include"consts.h"

using namespace std;
using namespace sf;


class Unity
{
protected:
	SoundBuffer _sbuf;
	Sound _deathSound, _walkingSound, _attackSound;

	Texture _unitTexture;
	Sprite _unitSprite;
	String _unitName;
	UnitSignature _unitSignature;

	RenderWindow *_window2D;

	int _health;
	Vector2i _unitSize;
	bool _isAlive;


public:
	Unity(RenderWindow &window2D, String name, Vector2i unitSize, Vector2f pos, UnitSignature unitSignature);
	virtual void move();
	void draw2D();

	Vector2f deltaPlusPos(Vector2f dPos);
	void setPosition(Vector2f dPos);
	void setAngle(int ang);

	UnitSignature  getUnitSignature();


	Vector2f getPosition();
	Vector2i getPositionMap();
	Vector2i getUnitSize();
	int getAngle();
};