#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
#include "string"

using namespace std;
using namespace sf;

//const string _Directory = "d:\\ETK\\Projects\\VCPP\\DungeonsII\\x64\\Debug\\";
const string _Directory = "C:\\Max\\my_created_games\\DungeonsII\\";

const Vector2i _cnstTxtrRect({ 0,07 });
const float _windowWidth = 1200;
const int _windowHeight = 800;
const int _TileSize = 32;
const int _TileSizeBit = 5;
const float _VisionAngle = 60;
const float Pi = 3.1415926;
const float GradToRad = Pi / 180;

const float MaxLength = 9999999;


const float _dAngle = _VisionAngle / _windowWidth * 10;
const int _sizeConst = _TileSize * _windowHeight * 7;

const int _MaxLairs = 255;
typedef string MapType[_MaxLairs];
typedef  char UnitType;

enum UnitSignature
{
	Wrong = 0,
	Wall = '0',
	Hidden = 'h',
	Parket = ' ',


	Player1 = 'A',
	Player2 = 'B',
	Player3 = 'C',
	Player4 = 'D',
	Player5 = 'E',
	Player6 = 'F',

	Bot1 = 'a',
	Bot2 = 'b',
	Bot3 = 'c',
	Bot4 = 'd',
	Bot5 = 'e',
	Bot6 = 'f',

};

enum Items
{
	type001
};

