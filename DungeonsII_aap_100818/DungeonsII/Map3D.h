#pragma once
#include<SFML\Graphics.hpp>
#include"consts.h"
using namespace sf;

class Map3D
{
private:
	RenderWindow *_window3D;
	MapType _rayMap;
	VertexArray pricel;
	VertexArray quad;

	Image _wall_Image;
	Texture _wall_Texture;
	Sprite _wall_Sprite;

	Image _bot_Image;
	Texture _bot_Texture;
	Sprite _bot_Sprite;

	inline UnitType getUnit(int x, int y);

public:
	Map3D(RenderWindow *window3D, int curLvlNum);
	void setMap(const MapType &map, const int& lairscount);

	///////////////////////////////////////////////////////////////////////////////////////////
	//void lines(const Vector2f &pos, const int angle);
	//void rayVertical(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length);
	//void rayHorizontal(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length);
	///////////////////////////////////////////////////////////////////////////////////////////
	void rayVertical(const Vector2f &pos, const float &sprAngle, const float &rayAngle, Vector2f &intersect, float &length);
	void rayHorizontal(const Vector2f &pos, const float &sprAngle, const float &rayAngle, Vector2f &intersect, float &length);
	void rayOnce(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length, UnitSignature &EnemyTypeIntersect, float &distanceToEnemy, bool &enemyHit);
	void rayOnce_(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, float &length, UnitSignature &EnemyTypeIntersect, float &distanceToEnemy, bool &enemyHit);

	//void rayOnceUnit(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, UnitSignature &typeIntersect, float &length , int& xPos);

	void showUnit3D(const int &xPos, const float &length, UnitSignature &typeIntersect);

	void window3Dshow(const int &xPos, const float &length);

	void window2Dshow(RenderWindow &window2D, const Vector2f &pos, const Vector2f &intersect);

	void rayCast(const Vector2f &pos, const float &sprAngle);


	void draw3DQuad();
	void draw3DPricel();

	~Map3D();
};

