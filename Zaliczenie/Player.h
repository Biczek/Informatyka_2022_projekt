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


	int health;
	bool shot;

	RectangleShape Gracz;
	CircleShape Bullet;

public:
	Player();

	void initVariables();

	void initPlayer();
	void updatePlayer(RenderTarget& target, float velocity);
	void renderPlayer(RenderTarget& target);

	void initBullet();
	void updateBullet(RenderTarget& target);
	void renderBullet(RenderTarget& target);
};



