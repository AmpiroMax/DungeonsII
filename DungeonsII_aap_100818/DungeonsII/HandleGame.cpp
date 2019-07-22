#include "HandleGame.h"
#include"SFML\Graphics\Text.hpp"
#include"view.h"
#include "Global.h"

HandleGame::HandleGame() : _window2D(VideoMode(_windowWidth, _windowHeight), "DangII"), _window3D(VideoMode(_windowWidth, _windowHeight), "DangI"), _map(&_window2D), _player(_window2D, "player", Vector2i(1, 1), Vector2f(5 * _TileSize, 3 * _TileSize), Player1), _map3D(&_window3D, _map.getCurLvlvNum())
{

	_window3D.setPosition({ 150,150 });
	_window2D.setPosition({ 800, 100 });

	_window3D.setMouseCursorVisible(false);
	_view.reset(sf::FloatRect(0, 0, 600, 400));

}

void HandleGame::initGame()
{
	vector<pair<Vector2i, UnitSignature>> units;
	_map.loadMap(0, units);
	initUnitFromMap(units);
	_map3D.setMap(_map.getMap(), _map.getLairsCount());
}

void HandleGame::HGHC(Vector2f &dPos)
{
	if (!Keyboard::isKeyPressed(Keyboard::P))
	{
		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::D))
		{
			float dx, dy;
			float mx, my;
			int ang = _player.getAngle();

			dx = _TileSize * cos(ang * 3.14 / 180);
			dy = _TileSize * sin(ang * 3.14 / 180);

			mx = _TileSize * cos((ang + 90) * 3.14 / 180);
			my = _TileSize * sin((ang + 90) * 3.14 / 180);

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				dPos.x = dx;
				dPos.y = dy;
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				dPos.x = -dx;
				dPos.y = -dy;
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				dPos.x = -mx;
				dPos.y = -my;
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				dPos.x = mx;
				dPos.y = my;
			}
			if (Keyboard::isKeyPressed(Keyboard::LAlt))
			{
				dPos.x *= 2;
				dPos.y *= 2;
			}
		}
		else
		{
			dPos = Vector2f(0, 0);
		}
		if (abs(Mouse::getPosition(_window3D).x - int(_windowWidth / 2)) > 5)
		{
			_player.setAngle((Mouse::getPosition(_window3D).x - int(_windowWidth / 2)) / 5);
		}
		Vector2i pos;
		pos.x = int(_windowWidth / 2);
		pos.y = int(_windowHeight / 2);
		Mouse::setPosition(pos, _window3D);
	}

}



void HandleGame::initUnitFromMap(const vector<pair<Vector2i, UnitSignature>>& units)
{
	int i = 0;
	for (const auto &data : units)
	{
		cout << "X:" << data.first.x << " y:" << data.first.y << " Type:" << data.second << std::endl;
		_enemies.push_back(Enemy(_window2D, "Enemy", Vector2i(1, 1), MapPosToScreenPos(data.first), UnitSignature(char(data.second) + i)));
		i++;
	}

}
void HandleGame::putUnitOnMap()
{
	for (Enemy &enemy : _enemies)
	{
		_map.putUnit(ScreenPosToMapPos(enemy.getPosition()), enemy.getUnitSignature(), enemy.getUnitSize());
	}


}
void HandleGame::removeUnitFromMap()
{
	for (Enemy &enemy : _enemies)
	{
		_map.putUnit(ScreenPosToMapPos(enemy.getPosition()), Parket, enemy.getUnitSize());
	}
}

void HandleGame::moveBots()
{
	Vector2f deltaPos;
	for (Enemy &enemy : _enemies)
	{
		enemy.move(deltaPos);
		if (_map.checkPos(enemy.deltaPlusPos(deltaPos), enemy.getUnitSize()))
		{
			enemy.setPosition(enemy.deltaPlusPos(deltaPos));
		}
	}

}

void HandleGame::game()
{
	//***************************************************************************
	//***************************************************************************
	//***************************************************************************

	Text text1, text2;
	Font font;
	if (!(font.loadFromFile("C:\\windows\\fonts\\arial.ttf")))
	{
		cout << "Error loading font " << std::endl;
	}
	text1.setCharacterSize(20);
	//_text1.setScale({100,70});
// SFML-2.5.0 depricated	text1.setColor(Color(100, 50, 30));
	text1.setFont(font);
	text1.setPosition({ 50 , 20 });

	text2.setCharacterSize(20);
	//_text2.setScale({ 100,70 });
// SFML-2.5.0 depricated	text2.setColor(Color(100, 50, 70));
	text2.setFont(font);
	text2.setPosition({ 50 , 50 });

	text1.setString("PAUSE - P");
	text2.setString("EXIT - H");

	initGame();
	//***************************************************************************
	//***************************************************************************
	//***************************************************************************

	Vector2f deltaPos;

	while ((_window2D.isOpen()) && (_window3D.isOpen()))
	{

		while (_window2D.pollEvent(_event) && (_window3D.pollEvent(_event)))
		{
			if (_event.type == Event::Closed)
			{
				_window2D.close();
				_window3D.close();
			}
		}

		HGHC(deltaPos);

		//moving player
		if (_map.checkPos(_player.deltaPlusPos(deltaPos)))
		{
			_player.setPosition(_player.deltaPlusPos(deltaPos));
		}

		//moving Enemies
		removeUnitFromMap();
		moveBots();
		putUnitOnMap();


		_window3D.clear(Color(140, 140, 140));
		_window2D.clear();

		///////////////////////////-Menu-///////////////////////////////////////////
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			_window3D.setMouseCursorVisible(true);
			text1.setString("CONTINUE - L");
			// SFML-2.5.0 depricated			text1.setColor(Color(30, 50, 100));
			_window3D.draw(text1);
			_window3D.display();
			while (!(Keyboard::isKeyPressed(Keyboard::L)))
			{

			}
			text1.setString("PAUSE - P");
			// SFML-2.5.0 depricated		text1.setColor(Color(100, 50, 30));
			_window3D.setMouseCursorVisible(false);
		}
		if (Keyboard::isKeyPressed(Keyboard::H))
		{
			_window2D.close();
			_window3D.close();
		}
		_window3D.draw(text1);
		_window3D.draw(text2);
		///////////////////////////////////////////////////////////////////////////

		//setting view
		my_setViewPosition(_player.getPosition());
		changeview();
		_window2D.setView(_view);

		//draw map on window2D
		_map.drawMap();
		_map.rayCast(_window3D,_player.getPosition(),_player.getAngle());

		
		_map3D.draw3DQuad();
		_map3D.setMap(_map.getMap(), _map.getLairsCount());
		_map3D.rayCast(_player.getPosition(), _player.getAngle());
		_map3D.draw3DPricel();
		_window2D.display();
		_window3D.display();


		sf::sleep(sf::milliseconds(1000 / 50));

	}
}

HandleGame::~HandleGame()
{

}
