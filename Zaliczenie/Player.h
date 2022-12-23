#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>

using namespace sf;


class Player
{
private:

	sf::RectangleShape Gracz;

public:
	Player();

	void initPlayer();
	void updatePlayer(RenderTarget& target, float velocity);
	void renderPlayer(RenderTarget& target);
};



