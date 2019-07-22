#include "unit.h"

Unity::Unity(RenderWindow &window2D ,String name, Vector2i unitSize, Vector2f pos, UnitSignature unitSignature)
{
	string partName;
	Image image;

	_health = 100;
	_unitSize = unitSize;
	_unitName = name;
	_unitSignature = unitSignature;
	_isAlive = true;

	_window2D = &window2D;

	partName = _Directory + "units\\" + char(_unitSignature) + ".png";
	image.loadFromFile(partName);
	_unitTexture.loadFromImage(image);
	_unitSprite.setTexture(_unitTexture);
	_unitSprite.setTextureRect(IntRect(0, 0, unitSize.x * _TileSize , unitSize.y * _TileSize));
	_unitSprite.setPosition(pos);
	_unitSprite.setOrigin(_TileSize/2 * _unitSize.x , _TileSize / 2 * _unitSize.x);

	partName = _Directory + "media\\" + char(_unitSignature) + "_deathSound" + ".ogg";
	_sbuf.loadFromFile(partName);
	_deathSound.setBuffer(_sbuf);

	partName = _Directory + "media\\" + char(_unitSignature) + "_walkingSound" + ".ogg";
	_sbuf.loadFromFile(partName);
	_walkingSound.setBuffer(_sbuf);

	partName = _Directory + "media\\" + char(_unitSignature) + "_attackSound" + ".ogg";
	_sbuf.loadFromFile(partName);
	_attackSound.setBuffer(_sbuf);

}

void Unity::move()
{
}

void Unity::draw2D()
{
	/*sf::VertexArray quad(sf::Quads, 4);

	float x = _unitSprite.getPosition().x;
	float y = _unitSprite.getPosition().y;

	quad[0].position = sf::Vector2f(x, y);
	quad[1].position = sf::Vector2f(x + _TileSize, y);
	quad[2].position = sf::Vector2f(x + _TileSize, y + _TileSize);
	quad[3].position = sf::Vector2f(x, y+_TileSize);

	_window2D->draw(quad);*/

	_window2D->draw(_unitSprite);
}

Vector2f Unity::deltaPlusPos(Vector2f dPos)
{
	return getPosition() + dPos;
}

void Unity::setPosition(Vector2f position)
{
	_unitSprite.setPosition(position);
}

void Unity::setAngle(int ang)
{
	_unitSprite.rotate(ang);
}

UnitSignature Unity::getUnitSignature()
{
	return _unitSignature;
}

Vector2f Unity::getPosition()
{
	return _unitSprite.getPosition();
}
Vector2i Unity::getPositionMap()
{
	Vector2i pos;
	pos.x = getPosition().x/ _TileSize;
	pos.y = getPosition().y/ _TileSize;
	return pos;
}

Vector2i Unity::getUnitSize()
{
	return _unitSize;
}

int Unity::getAngle()
{
	return _unitSprite.getRotation();
}
