#include "HandleGame.h"
#include <iostream>
//sfml-graphics-d.lib;sfml-window-d.lib;sfml-network-d.lib;sfml-system-d.lib;sfml-audio-d.lib;
//C:\Max\Projects\sfml_library\SFML-2.3.2-windows-vc14-64-bit\SFML-2.3.2\lib
//To do:
//досмотреть фильм союзники земекиса



int main()
{
	
	HandleGame Game;
	Game.game();
	return 0;
}

/*

int i = 0, px, py, alpha , dx , dy , betta , l;
RenderWindow window(VideoMode(620, 480), "DangeonsII");
Event event;
_view.reset(sf::FloatRect(0, 0, 640, 480));
VertexArray lines(Lines, 4);

px = 300;
py = px;
l = 100;

alpha = 60;
betta = 0;

lines[0].position = sf::Vector2f(px , py);
lines[1].position = sf::Vector2f(px + l * cos(betta * 3.14 / 180) , py - l * sin(betta * 3.14 / 180));
lines[2].position = lines[0].position;
lines[3].position = sf::Vector2f(px + l * cos((betta + alpha) * 3.14 / 180), py - l * sin((betta + alpha) * 3.14 / 180));


while (window.isOpen())
{
while (window.pollEvent(event))
{
if (event.type == Event::Closed)

window.close();
}

window.clear();

lines[0].position = sf::Vector2f(px, py);
lines[1].position = sf::Vector2f(px + l * cos(betta * 3.14 / 180), py - l * sin(betta * 3.14 / 180));
lines[2].position = lines[0].position;
lines[3].position = sf::Vector2f(px + l * cos((betta + alpha) * 3.14 / 180), py - l * sin((betta + alpha) * 3.14 / 180));

if (Keyboard::isKeyPressed(Keyboard::A)) {
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
}

window.draw(lines);


*/