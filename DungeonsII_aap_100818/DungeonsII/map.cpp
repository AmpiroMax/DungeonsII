#include "map.h"
#include <math.h>
#include <chrono>
#include <iostream>

Map::Map(RenderWindow *window)
{
	_enemyCount = 0;
	_curLocNum = 4;
	_curLvlNum = 1;
	//****************************************************************************************
	_opener = _Directory + "Levels" + "\\" + "level" + to_string(_curLvlNum) + "\\" + "mapWithBots.png";//добавить карты к каждому уровню SUKA
	cout << "Texture " << _opener << endl;
	_mapImage.loadFromFile(_opener);
	_mapTexture.loadFromImage(_mapImage);
	_mapSprite.setTexture(_mapTexture);
	//****************************************************************************************
	_opener = _Directory + "Levels" + "\\" + "count.txt";
	_file.open(_opener);
	s_reader = "";
	while (_file.read((char*)&_reader, sizeof(_reader)))
	{
		s_reader = s_reader + _reader;
	}
	_lvlCount = atoi(s_reader.c_str());
	_file.close();
	//----------------------------------//----------------------------------//----------------------------------
	_opener = _Directory + "Levels" + "\\" + "level" + to_string(_curLvlNum) + "\\" + "count.txt";
	_file.open(_opener);
	s_reader = "";
	while (_file.read((char*)&_reader, sizeof(_reader)))
	{
		s_reader = s_reader + _reader;
	}
	_locCount = atoi(s_reader.c_str());
	_file.close();
	//****************************************************************************************
	_window = window;
}

void Map::setLevel(int levelNum)
{
	_curLvlNum = levelNum;
}

void Map::setLocation(int locationNum)
{
	_curLocNum = locationNum;
}

void Map::LocationCounter()
{
	_opener = _Directory + "Levels" + "\\" + "level" + to_string(_curLvlNum) + "\\" + "count.txt";
	_file.open(_opener);
	s_reader = "";
	while (_file.read((char*)&_reader, sizeof(_reader)))
	{
		s_reader = s_reader + _reader;
	}
	_locCount = atoi(s_reader.c_str());
	_file.close();
}


void Map::loadMap(int del, vector<pair<Vector2i, UnitSignature>> &units)
{
	int i = 0;
	_curLocNum = _curLocNum + del;
	if (_curLocNum > _locCount)
	{
		_curLocNum = 1;
		_curLvlNum += 1;
		this->LocationCounter();
	}
	if (_curLvlNum > _lvlCount)
	{
		_window->close();
	}

	_opener = _Directory + "Levels" + "\\" + "level" + to_string(_curLvlNum) + "\\" + "location" + to_string(_curLocNum) + ".txt";
	_file.open(_opener);
	if (!_file.is_open())
		cout << "Error load map" << _opener;

	while (_file.read((char*)&_reader, sizeof(_reader)))
	{
		//cout << _reader;
		if ((_reader != Parket) && (_reader != Wall) && (_reader != '\n'))
		{
			_enemyCount += 1;
			_map[i] = _map[i] + ' ';

			std::pair<Vector2i, UnitSignature> data(Vector2i(_map[i].length(), i), UnitSignature(_reader));
			//cout << "X: " << _map[i].length() << "Y: " << i << " " << _reader << endl;
			units.push_back(data);
		}
		else
		{
			_map[i] = _map[i] + _reader;
		}

		if (_reader == '\n')
		{

			cout << _map[i];
			i++;
		}


	}
	_lairsCount = i + 1;
}

void Map::drawMap()
{
	int d = 0, D = 0;
	for (int i = 0; i <= _lairsCount; i++)
		for (int j = 0; j < _map[i].length(); j++)
		{
			//
			//cout << _map[i][j];
			switch (getUnit(j, i))
				//switch (_map[i][j])
			{
			case ' ': {
				_mapSprite.setTextureRect(IntRect(96, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
									   //i++;
				break;
			}
			case '2': {
				_mapSprite.setTextureRect(IntRect(64, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
									   //i++;
				break;
			}
			case '1': {
				_mapSprite.setTextureRect(IntRect(32, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
									   //i++;
				break;
			}
			case '0': {
				_mapSprite.setTextureRect(IntRect(32, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
			case 'a': {
				_mapSprite.setTextureRect(IntRect(32 * 8, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
									   //i++;
				break;
			}
			case 'b': {
				_mapSprite.setTextureRect(IntRect(32 * 9, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
			case 'c': {
				_mapSprite.setTextureRect(IntRect(32 * 10, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
			case 'd': {
				_mapSprite.setTextureRect(IntRect(32 * 11, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
			case 'e': {
				_mapSprite.setTextureRect(IntRect(32 * 12, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
			case 'f': {
				_mapSprite.setTextureRect(IntRect(32 * 13, 0, 32, 32));
				_mapSprite.setPosition(j * _TileSize, i * _TileSize);
				_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
					  /*case 'd': {
						  if (d == 0)
						  {
							  _mapSprite.setTextureRect(IntRect(128, 0, 32, 32));
							  _mapSprite.setPosition(j * _TileSize, i * _TileSize);
							  _window->draw(_mapSprite);
						  }
						  if (d == 1)
						  {
							  _mapSprite.setTextureRect(IntRect(160, 0, 32, 32));
							  _mapSprite.setPosition(j * _TileSize, i * _TileSize);
							  _window->draw(_mapSprite);
						  }
						  d = 1;
						  break;
					  }
					  case 'D': {
						  if (D == 0)
						  {
							  _mapSprite.setTextureRect(IntRect(192, 0, 32, 32));
							  _mapSprite.setPosition(j * _TileSize, i * _TileSize);
							  _window->draw(_mapSprite);

						  }
						  if (D == 1)
						  {
							  _mapSprite.setTextureRect(IntRect(224, 0, 32, 32));
							  _mapSprite.setPosition(j * _TileSize, i * _TileSize);
							  _window->draw(_mapSprite);
						  }
						  D = 1;
						  break;
					  }*/
			case '-': {//
				//_mapSprite.setTextureRect(IntRect(128, 0, 32, 32));
				//_mapSprite.setPosition(i * 32, j * 32);
				//_window->draw(_mapSprite);//рисуем квадратики на экран
										  //i++;
				break;
			}
			default: {

			}
			}
		}




	//cout<<endl;
}

void Map::lines(const Vector2f & pos, const int angle)
{
	int i = 0, px = pos.x, py = pos.y, alpha, dx, dy, betta, l;
	VertexArray lines(Lines, 6);

	l = 100;
	betta = angle - 30;


	/*lines[0].position = sf::Vector2f(px, py);
	lines[1].position = sf::Vector2f(px + l * cos(betta * 3.14 / 180), py - l * sin(betta * 3.14 / 180));
	lines[2].position = lines[0].position;
	lines[3].position = sf::Vector2f(px + l * cos((betta + _VisionAngle) * 3.14 / 180), py - l * sin((betta + _VisionAngle) * 3.14 / 180));*/
	lines[4].position = pos;
	lines[5].position = sf::Vector2f(pos.x + 2 * l*cos((betta + 30) * 3.14 / 180), pos.y + 2 * l*sin((betta + 30) * 3.14 / 180));
	lines[0].color = sf::Color::Green;
	lines[1].color = sf::Color::Green;
	lines[2].color = sf::Color::Green;
	lines[3].color = sf::Color::Red;
	lines[5].color = sf::Color::Red;


	/*if (Keyboard::isKeyPressed(Keyboard::A)) {
		betta += 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		betta -= 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		dx = (lines[1].position.x + (lines[3].position.x - lines[1].position.x) / 2);
		dy = (lines[1].position.y + (lines[3].position.y - lines[1].position.y) / 2);

		dx = (lines[0].position.x - dx) / 30;
		dy = (lines[0].position.y - dy) / 30;

		px -= dx;
		py -= dy;
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {

		dx = (lines[1].position.x + (lines[3].position.x - lines[1].position.x) / 2);
		dy = (lines[1].position.y + (lines[3].position.y - lines[1].position.y) / 2);

		dx = (lines[0].position.x - dx) / 30;
		dy = (lines[0].position.y - dy) / 30;

		px += dx;
		py += dy;
	}*/
	_window->draw(lines);
}

void Map::rayVertical(const Vector2f & pos, const float & sprAngle, float & rayAngle, Vector2f &intersect, float &length)
{
	if ((rayAngle == 90) || (rayAngle == 270))
	{
		length = MaxLength;
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
	float bx = Bx / 256,
		by = By / 256;
	length = ((pos.x - bx)*(pos.x - bx) + (pos.y - by)*(pos.y - by));

	intersect.x = bx;
	intersect.y = by;
}



void Map::rayHorizontal(const Vector2f & pos, const float & sprAngle, float & rayAngle, Vector2f &intersect, float &length)
{
	if ((rayAngle == 0) || (rayAngle == 180))
	{
		length = MaxLength;
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

	float ax = Ax / 256,
		ay = Ay / 256;


	length = ((pos.x - ax)*(pos.x - ax) + (pos.y - ay)*(pos.y - ay));

	intersect.x = ax;
	intersect.y = ay;
}
void Map::rayOnce(const Vector2f & pos, const float & sprAngle, float & rayAngle, Vector2f & intersect, float & length)
{
	//---------------------------------------

	int length1 = NULL, length2 = NULL;
	Vector2f inters1, inters2;
	using namespace std;
	using namespace std::chrono;
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

	std::chrono::high_resolution_clock::time_point t2 = high_resolution_clock::now();

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
	else if (length1 < length2)//выбираем ближайшее пересечение
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
	length = sqrt(length)*cos((rayAngle - sprAngle)*GradToRad);

	/*
	//---------------------------------------
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
		while (_map[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize] != Wall)
		{
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

	length = sqrt((pos.x - intersect.x)*(pos.x - intersect.x) + (pos.y - intersect.y)*(pos.y - intersect.y)) * cos((rayAngle - sprAngle)*gradToRad);
	rayAngle = -rayAngle;
	*/
}

void Map::rayOnceUnit(const Vector2f &pos, const float &sprAngle, float &rayAngle, Vector2f &intersect, UnitSignature &typeIntersect, float &length)
{
	float gradToRad = 3.14 / 180;
	intersect.x = pos.x;
	intersect.y = pos.y;
	float Xa, Ya;
	rayAngle = -rayAngle;
	Xa = cos(rayAngle*gradToRad);
	Ya = sin(rayAngle*gradToRad);
	while (_map[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize] == Parket)
	{
		intersect.x += Xa;
		intersect.y += Ya;

	}
	length = sqrt((pos.x - intersect.x)*(pos.x - intersect.x) + (pos.y - intersect.y)*(pos.y - intersect.y)) * cos((rayAngle - sprAngle)*gradToRad);
	typeIntersect = UnitSignature(_map[int(intersect.y) / _TileSize][int(intersect.x) / _TileSize]);
	rayAngle = -rayAngle;
}




void Map::window2Dshow(const Vector2f & pos, const Vector2f & intersect)
{
	sf::VertexArray line(sf::Lines, 2);

	line[0].position = pos;
	line[1].position = intersect;
	_window->draw(line);
}

void Map::rayCast(RenderWindow &window3D, const Vector2f & pos, const float & sprAngle)
{
	float rayAngle = -int(sprAngle) + 30;
	float length = 0;
	Vector2f intersect;
	UnitSignature typeIntersect;



	for (int i = 0; i < _windowWidth / 10; i++)
	{
		if (rayAngle < 0)rayAngle += 360;
		if (rayAngle > 360)rayAngle -= 360;

		rayOnce(pos, sprAngle, rayAngle, intersect, length);
		//window2Dshow(pos, intersect);
		//length = _sizeConst / length;
		//window3Dshow(i, length, window3D);

		//rayOnceUnit(pos, sprAngle, rayAngle, intersect, typeIntersect, length);
		window2Dshow(pos, intersect);
		//length = _sizeConst / length;
		//showUnit3D(i, length, window3D, typeIntersect);

		rayAngle -= _dAngle;

	}

	lines(pos, sprAngle);
}



int Map::getEnemyCount()
{
	return _enemyCount;
}

int Map::iterWithPlayer(Vector2f pos)
{
	int cross = 1;
	for (int i = int(pos.x / _TileSize); i < int((pos.x + _TileSize) / _TileSize); i++)
		for (int j = int(pos.y / _TileSize); j < int((pos.y + _TileSize) / _TileSize); j++)
		{
			if ((_map[j][i] != '0'))
			{
				cross = -1;
			}
		}
	return cross;
}

UnitType Map::getUnit(Vector2i pos)
{
	if (pos.x < 0 || pos.y < 0)
		return Wrong;
	int x = pos.x / _TileSize,
		y = pos.y / _TileSize;

	if (y < _MaxLairs && x < _map[y].length())
		return _map[x][y];
	return Wrong;
}

UnitType Map::getUnit(int x, int y)
{
	if (x >= 0 && y >= 0 && y < _MaxLairs && x < _map[y].length()) 	return (UnitType)_map[y][x];
	//if (x >= 0 && y >= 0 && x < _MaxLairs && y < _map[x].length())		return (UnitType)_map[x][y];
	return Wrong;
}


bool Map::checkPos(Vector2f pos, Vector2i unitSize)
{
	for (int i = int(pos.x / _TileSize); i < int((pos.x + _TileSize * unitSize.x) / _TileSize); i++)
		for (int j = int(pos.y / _TileSize); j < int((pos.y + _TileSize * unitSize.y) / _TileSize); j++)
		{
			if ((_map[j][i] != Parket) && (_map[j][i] != Hidden))
			{
				return false;
			}
		}
	return true;
}
void Map::putUnit(Vector2i posMap, UnitSignature unitSignature, Vector2i unitSize)
{
	//if ((_map[posMap.x][posMap.y] != Wall))
	for (int i = 0; i < unitSize.y; i++)
		for (int j = 0; j < unitSize.x; j++)
		{
			_map[posMap.y + i][posMap.x + j] = unitSignature;
		}



}

MapType&  Map::getMap()
{
	return _map;
}

int Map::getLairsCount()
{
	return _lairsCount;
}

int Map::getCurLvlvNum()
{
	return _curLvlNum;
}

