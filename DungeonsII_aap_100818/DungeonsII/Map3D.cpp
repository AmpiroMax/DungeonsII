#include "Map3D.h"



Map3D::Map3D(RenderWindow *window3D, int curLvlNum)
{
	_window3D = window3D;
	////////////////////////////////////////////////////////////////////////////
	pricel = VertexArray(Lines, 4);
	pricel[0].position = sf::Vector2f(_windowWidth / 2 - 20, _windowHeight / 2);
	pricel[1].position = sf::Vector2f(_windowWidth / 2 + 20, _windowHeight / 2);

	pricel[2].position = sf::Vector2f(_windowWidth / 2, _windowHeight / 2 - 20);
	pricel[3].position = sf::Vector2f(_windowWidth / 2, _windowHeight / 2 + 20);
	pricel[0].color = Color(150, 255, 0);
	pricel[1].color = Color(150, 255, 0);
	pricel[2].color = Color(150, 255, 0);
	pricel[3].color = Color(150, 255, 0);
	////////////////////////////////////////////////////////////////////////////
	quad = VertexArray(Quads , 4);
	quad[0].position = sf::Vector2f(0, 0);
	quad[1].position = sf::Vector2f(_windowWidth, 0);
	quad[2].position = sf::Vector2f(_windowWidth, _windowHeight / 2);
	quad[3].position = sf::Vector2f(0, _windowHeight / 2);

	quad[0].color = Color(70, 70, 70);
	quad[1].color = Color(70, 70, 70);
	quad[2].color = Color(70, 70, 70);
	quad[3].color = Color(70, 70, 70);
	////////////////////////////////////////////////////////////////////////////
	string _opener;
	_opener = _Directory + "Levels" + "\\" + "level" + to_string(curLvlNum) + "\\" + "wall.png";
	_wall_Image.loadFromFile(_opener);
	_wall_Texture.loadFromImage(_wall_Image);
	_wall_Sprite.setTexture(_wall_Texture);
	////////////////////////////////////////////////////////////////////////////
	_opener = _Directory + "Levels" + "\\" + "level" + to_string(curLvlNum) + "\\" + "bot.png";
	_bot_Image.loadFromFile(_opener);
	_bot_Image.createMaskFromColor(Color(181,230,29));
	_bot_Texture.loadFromImage(_bot_Image);
	_bot_Sprite.setTexture(_bot_Texture);
}

void Map3D::setMap(const MapType &map , const int& lairsCount)
{
	for (int i = 0; i < lairsCount; i++)
	{
		_rayMap[i] = map[i];
	}

}

void Map3D::rayVertical(const Vector2f & pos, const float & sprAngle, const float & rayAngle, Vector2f &intersect, float &length)
{
	if ((rayAngle == 90) || (rayAngle == 270))
	{
		length = MaxLength;
		intersect.x = MaxLength;
		intersect.y = MaxLength;
		return;
	}
	float tangRay = tan(rayAngle*GradToRad) * 256;

	int dXb = 0, dYb = 0, Bx = pos.x, By = pos.y * 256;

	int dx = int(pos.x) % _TileSize;


	if ((0 < rayAngle) && (rayAngle < 90))
	{
		Bx = pos.x + (_TileSize - dx);
		dXb = _TileSize;
		By = By - (_TileSize - dx)*tangRay;
		dYb = -_TileSize*tangRay;

	}
	if ((90 < rayAngle) && (rayAngle < 180))
	{
		Bx = pos.x - dx - 1;
		dXb = -_TileSize;
		By = By + dx*tangRay;
		dYb = _TileSize*tangRay;
	}
	if ((180 < rayAngle) && (rayAngle < 270))
	{
		Bx = pos.x - dx - 1;
		dXb = -_TileSize;
		By = By + dx*tangRay;
		dYb = _TileSize*tangRay;
	}
	if ((270 < rayAngle) && (rayAngle < 360))
	{
		Bx = pos.x + (_TileSize - dx);
		dXb = _TileSize;
		By = By - (_TileSize - dx)*tangRay;
		dYb = -_TileSize*tangRay;
	}


	if ((rayAngle == 0))
	{
		Bx = pos.x + (_TileSize - dx);
		dXb = _TileSize;
		By = By;
		dYb = 0;
	}

	if ((rayAngle == 180))
	{
		Bx = pos.x - dx - 1;
		dXb = -_TileSize;
		By = By;
		dYb = 0;
	}
	Bx <<= 8;
	dXb <<= 8;

	int ix = Bx >> _TileSizeBit + 8;
	int iy = By >> _TileSizeBit + 8;
	UnitType  unit;
	while ((unit = getUnit(ix, iy)) != Wall && unit != Wrong)
	{
		Bx += dXb;
		By += dYb;
		ix = Bx >> _TileSizeBit + 8;
		iy = By >> _TileSizeBit + 8;

	}
	int bx = Bx / 256,
		by = By / 256;
	length = ((pos.x - bx)*(pos.x - bx) + (pos.y - by)*(pos.y - by));

	intersect.x = bx;
	intersect.y = by;
}



void Map3D::rayHorizontal(const Vector2f & pos, const float & sprAngle, const float & rayAngle, Vector2f &intersect, float &length)
{
	if ((rayAngle == 0) || (rayAngle == 180))
	{
		length = MaxLength;
		intersect.x = MaxLength;
		intersect.y = MaxLength;
		return;
	}


	bool isNull = false;
	float tangRay = tan(rayAngle*GradToRad) / 256;
	int Ax = pos.x * 256, Ay = pos.y, dXa = 0, dYa = 0;
	int dy = int(pos.y) % _TileSize;

	if ((0 < rayAngle) && (rayAngle < 90))
	{
		Ax = Ax + dy / tangRay;
		dXa = _TileSize / tangRay;
		Ay = pos.y - dy - 1;
		dYa = -_TileSize;
	}

	if ((90 < rayAngle) && (rayAngle < 180))
	{
		Ax = Ax + dy / tangRay;
		dXa = _TileSize / tangRay;
		Ay = pos.y - dy - 1;
		dYa = -_TileSize;
	}

	if ((180 < rayAngle) && (rayAngle < 270))
	{
		Ax = Ax - (_TileSize - dy) / tangRay;
		dXa = -_TileSize / tangRay;
		Ay = pos.y + (_TileSize - dy);
		dYa = _TileSize;
	}

	if ((270 < rayAngle) && (rayAngle < 360))
	{
		Ax = Ax - (_TileSize - dy) / tangRay;
		dXa = -_TileSize / tangRay;
		Ay = pos.y - dy + _TileSize;
		dYa = _TileSize;
	}

	if ((rayAngle == 90))
	{
		Ay = pos.y - dy - 1;
		dYa = -_TileSize;
		Ax = Ax;
		dXa = 0;
	}

	if ((rayAngle == 270))
	{
		Ay = pos.y + (_TileSize - dy);
		dYa = _TileSize;
		Ax = Ax;
		dXa = 0;
	}
	Ay <<= 8;
	dYa <<= 8;


	int ix = Ax >> _TileSizeBit + 8;
	int iy = Ay >> _TileSizeBit + 8;
	UnitType  unit;
	while ((unit = getUnit(ix, iy)) != Wall && unit != Wrong)	//while (!((ix < 0) || (iy < 0) || (iy >= _lairsCount) || (_map[iy].length() < ix) || (_map[iy][ix] == Wall)))
	{
		Ax += dXa;
		Ay += dYa;
		ix = Ax >> _TileSizeBit + 8;
		iy = Ay >> _TileSizeBit + 8;

	}
//	Ax >>= 8;
//	Ay >>= 8;

	int ax = Ax / 256,
		ay = Ay / 256;


	length = ((pos.x - ax)*(pos.x - ax) + (pos.y - ay)*(pos.y - ay));
	//length = (pos.x - intersect.x) * cos((rayAngle - sprAngle)*GradToRad) + 
	intersect.x = ax;
	intersect.y = ay;
}
void Map3D::rayOnce(const Vector2f & pos, const float & sprAngle, float & rayAngle, Vector2f & intersect, float & length, UnitSignature &EnemyTypeIntersect, float &distanceToEnemy, bool &enemyHit)
{
	//---------------------------------------

	int length1 = NULL, length2 = NULL;
	Vector2f inters1, inters2;
	using namespace std;
//	using namespace std::chrono;
//	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
//	std::chrono::high_resolution_clock::time_point t2 = high_resolution_clock::now();

	//	auto duration = duration_cast<microseconds>(t2 - t1).count();
	///////////////////////////////////////////////////////////////////////////////////

	rayHorizontal(pos, sprAngle, rayAngle, intersect, length);
	length1 = length;
	inters1 = intersect;

	///////////////////////////////////////////////////////////////////////////////////

	rayVertical(pos, sprAngle, rayAngle, intersect, length);
	length2 = length;
	inters2 = intersect;


	///////////////////////////////////////////////////////////////////////////////
/*
	if (length1 == 0)
	{
		length = length2;
		intersect = inters2;
		//cout << "Vertical" << endl;
	}
	else if (length2 == 0)
	{
		length = length1;
		intersect = inters1;
		//cout << "Horizontal" << endl;
	}
	*/
	 if (length1 < length2)//выбираем ближайшее пересечение
	{
		length = length1;
		intersect = inters1;
		//cout << "Horizontal" << endl;
	}
	else
	{
		length = length2;
		intersect = inters2;
		//cout << "Vertical" << endl;
	}




	 length = sqrt(length) *cos((rayAngle - sprAngle)*GradToRad);// *cos((rayAngle - sprAngle)*GradToRad);

	
}
UnitType Map3D::getUnit(int x, int y)
{
	if (x >= 0 && y >= 0 && y < _MaxLairs && x < _rayMap[y].length()) 	return (UnitType)_rayMap[y][x];
	//if (x >= 0 && y >= 0 && x < _MaxLairs && y < _rayMap[x].length())		return (UnitType)_rayMap[x][y];
	return Wrong;
}

void Map3D::rayOnce_(const Vector2f & pos, const float & sprAngle, float & rayAngle, Vector2f & intersect, float &length , UnitSignature &EnemyTypeIntersect, float &distanceToEnemy, bool &enemyHit)
{
	float gradToRad = 3.14 / 180;
	intersect.x = pos.x;
	intersect.y = pos.y;
	float Xa, Ya, dX, dY;
	rayAngle = -rayAngle;
	dX = cos(rayAngle*gradToRad);
	dY = sin(rayAngle*gradToRad);
	Xa = dX * _TileSize;
	Ya = dY * _TileSize;

	for (int i = 0; i < 2; i++)
	{
		while (_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize] != Wall)
		{
			if ((_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize] != Parket)&&(!enemyHit))
			{
				enemyHit = true;
				distanceToEnemy = sqrt((pos.x - intersect.x)*(pos.x - intersect.x) + (pos.y - intersect.y)*(pos.y - intersect.y)) * cos((rayAngle - sprAngle)*gradToRad);
				EnemyTypeIntersect = UnitSignature(_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize]);
			}
			intersect.x += Xa;
			intersect.y += Ya;
		}
		if (i == 0) {
			intersect.x -= Xa;
			intersect.y -= Ya;
			Xa = dX;
			Ya = dY;
		}
	}

	length = sqrt((pos.x - intersect.x)*(pos.x - intersect.x) + (pos.y - intersect.y)*(pos.y - intersect.y));// *cos((rayAngle - sprAngle)*gradToRad);
	rayAngle = -rayAngle;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void Map3D::rayOnceUnit(const Vector2f & pos, const float & sprAngle, float & rayAngle, Vector2f & intersect, UnitSignature & typeIntersect, float & length, int& xPos)
//{
//	float gradToRad = 3.14 / 180;
//	intersect.x = pos.x;
//	intersect.y = pos.y;
//	float Xa, Ya;
//	rayAngle = -rayAngle;
//	Xa = cos(rayAngle*gradToRad);
//	Ya = sin(rayAngle*gradToRad);
//	while (_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize] == Parket)
//	{
//		if (_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize] != Parket)
//		{
//			length = sqrt((pos.x - intersect.x)*(pos.x - intersect.x) + (pos.y - intersect.y)*(pos.y - intersect.y)) * cos((rayAngle - sprAngle)*gradToRad);
//			typeIntersect = UnitSignature(_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize]);
//			showUnit3D(xPos , _sizeConst / length, typeIntersect);
//		}
//		intersect.x += Xa;
//		intersect.y += Ya;
//
//	}
//	length = sqrt((pos.x - intersect.x)*(pos.x - intersect.x) + (pos.y - intersect.y)*(pos.y - intersect.y)) * cos((rayAngle - sprAngle)*gradToRad);
//	typeIntersect = UnitSignature(_rayMap[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize]);
//	rayAngle = -rayAngle;
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Map3D::showUnit3D(const int & xPos, const float & length, UnitSignature & typeIntersect)
{
	if ((typeIntersect != Parket) && (typeIntersect != Wall))
	{
		sf::VertexArray line(sf::Lines, 2);
		for (int i = xPos * 10; i < xPos * 10 + 10; i++)
		{
			line[0].position = sf::Vector2f({ float(i) , _windowHeight / 2 });
			line[0].color = Color(200, typeIntersect * 50, 0);
			line[1].position = sf::Vector2f({ float(i) , _windowHeight / 2 + length / 2 });
			line[1].color = Color(200, typeIntersect * 50, typeIntersect * 30);
			_window3D->draw(line);
		}

		/*_bot_Sprite.setScale(1, length / 90);
		for (int i = xPos * 10; i < xPos * 10 + 10; i++)
		{
			_bot_Sprite.setPosition(float(i), _windowHeight / 2 - length / 2);
			_bot_Sprite.setTextureRect(IntRect(i % 90, 0, 1, 90));
			_window3D->draw(_bot_Sprite);
		}*/
	}
}

void Map3D::window3Dshow(const int & xPos, const float & length)
{
	_wall_Sprite.setScale(1, length / 90);
	sf::VertexArray line(sf::Lines, 2);
	for (int i = xPos * 10; i < xPos * 10 + 10; i++)
	{
		_wall_Sprite.setPosition(float(i), _windowHeight / 2 - length / 2);
		_wall_Sprite.setTextureRect(IntRect(90 - i % 90, 0, -1, 90));
		_window3D->draw(_wall_Sprite);
	}

	line[0].position = sf::Vector2f({ float(xPos * 10) , _windowHeight / 2 - length / 2 });
	line[0].color = Color(0, 0, 0);
	line[1].position = sf::Vector2f({ float(xPos * 10 + 10) , _windowHeight / 2 - length / 2 });
	line[1].color = Color(0, 0, 0);
	_window3D->draw(line);

	line[0].position = sf::Vector2f({ float(xPos * 10) , _windowHeight / 2 + length / 2 });
	line[0].color = Color(0, 0, 0);
	line[1].position = sf::Vector2f({ float(xPos * 10 + 10) , _windowHeight / 2 + length / 2 });
	line[1].color = Color(0, 0, 0);
	_window3D->draw(line);
}

void Map3D::window2Dshow(RenderWindow & window2D, const Vector2f & pos, const Vector2f & intersect)
{
}

void Map3D::rayCast(const Vector2f & pos, const float & sprAngle)
{
	float rayAngle = -int(sprAngle) + 30;
	float length = 0;
	float distanceToEnemy = 0;
	bool enemyHit = false;

	Vector2f intersect;
	UnitSignature typeIntersect;
	UnitSignature enemyTypeIntersect;



	for (int i = 0; i < _windowWidth / 10; i++)
	{
		if (rayAngle < 0)rayAngle += 360;
		if (rayAngle > 360)rayAngle -= 360;

		rayOnce(pos, sprAngle, rayAngle, intersect, length, enemyTypeIntersect, distanceToEnemy,enemyHit);
		length = _sizeConst / length;
		window3Dshow(i, length);

		/*rayOnceUnit(pos, sprAngle, rayAngle, intersect, typeIntersect, length);*/
		if (enemyHit)
		{
			distanceToEnemy = _sizeConst / distanceToEnemy;
			showUnit3D(i, distanceToEnemy, enemyTypeIntersect);
		}
		enemyHit = false;
		rayAngle -= _dAngle;

	}
}


void Map3D::draw3DQuad()
{
	_window3D->draw(quad);
}

void Map3D::draw3DPricel()
{
	_window3D->draw(pricel);
}

Map3D::~Map3D()
{
}
