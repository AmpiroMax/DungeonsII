#include "Global.h"



/////////////////////////////////////////////////////////////////
//
Vector2i ScreenPosToMapPos(Vector2f vector2f) 
{
	Vector2i  vector2i;
	vector2i.x = (int) vector2f.x / _TileSize;
	vector2i.y = (int) vector2f.y / _TileSize;
	return vector2i;
};

/////////////////////////////////////////////////////////////////
//
Vector2f MapPosToScreenPos(Vector2i vector2i) {
	Vector2f  vector2f;
	vector2f.x = (float) vector2i.x * _TileSize;
	vector2f.y = (float) vector2i.y * _TileSize;
	return vector2f;
};

/////////////////////////////////////////////////////////////////
//

Global::Global()
{
}


Global::~Global()
{
}
