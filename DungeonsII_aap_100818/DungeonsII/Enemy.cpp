#include "Enemy.h"



Enemy::Enemy(RenderWindow &window2D ,String name, Vector2i unitSize, Vector2f pos , UnitSignature unitSignature) :Unity( window2D ,name, unitSize, pos, unitSignature)
{

}

 void Enemy::move(Vector2f &dPos)
{
	float dx, dy;

	dx = _TileSize ;
	dy = _TileSize ;

	dPos.x = dx * (rand() % 3 - 1);
	dPos.y = dy * (rand() % 3 - 1);

}



Enemy::~Enemy()
{
}
