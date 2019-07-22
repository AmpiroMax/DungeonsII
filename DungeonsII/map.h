#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<iostream>
#include<string.h>
#include<fstream>
#include"consts.h"

using namespace std;
using namespace sf;

class Map
{
private:
	RenderWindow *_window;
	Image _mapImage;
	Texture _mapTexture;
	Sprite _mapSprite;

	int _curLvlNum;
	int _curLocNum;
	int _locCount;
	int _lvlCount;
	int _lairsCount;
	int _enemyCount;

	fstream _file;
	string _opener;
	char _reader;
	string s_reader;

protected:
	MapType _map;


public:
	Map(RenderWindow *window);
	void setLevel(int levelNum);
	void setLocation(int locationNum);
	void LocationCounter();
	void loadMap(int del , vector<pair<Vector2i, UnitSignature>> &units);
	void drawMap();

	void lines(const Vector2f &pos, const int angle);
	void rayVertical(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length);
	void rayHorizontal(const Vector2f &pos , const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length);

	void rayOnce(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length);
	void rayOnceUnit(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, UnitSignature &typeIntersect, float &length);

	void window2Dshow(const Vector2f &pos,const Vector2f &intersect);
	void rayCast(RenderWindow &window3D,const Vector2f &pos ,const float &sprAngle);
	
	int getEnemyCount();
	int iterWithPlayer(Vector2f pos);
	
	inline UnitType getUnit(Vector2i pos);
	inline UnitType getUnit(int x, int y);


	bool checkPos(Vector2f pos, Vector2i unitSize = Vector2i(1, 1));
	void putUnit(Vector2i pos, UnitSignature unitSignature, Vector2i unitSize);

	

	MapType& getMap();
	int getLairsCount();
	int getCurLvlvNum();
};