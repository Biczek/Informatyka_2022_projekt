#pragma once
#include"Player.h"


class Bullet
{
private:
	int max_bullets = 3;
	int timer = 0;
	int max_timer = 5;

	CircleShape bullet;
	vector<sf::CircleShape>bullets;

public:
	Bullet();

	void updateBullet(float x, float y);
	void renderBullet(RenderTarget& target);
	void spawnBullet(float x, float y);
};

