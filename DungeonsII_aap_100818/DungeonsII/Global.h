#pragma once
#include "consts.h"



Vector2i ScreenPosToMapPos(Vector2f vector2f);
Vector2f MapPosToScreenPos(Vector2i vector2i);

class Global
{
public:
	Global();
	~Global();
};

