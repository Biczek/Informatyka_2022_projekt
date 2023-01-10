#pragma once
#include "Player.h"


class Enemies
{
private:

	int hp;
	int hp_max;
	int demage;

	int timer; 
	int timer_max;
	int max_enemies;

	float velocity;

public:
	sf::ConvexShape enemy;

	Enemies(float pos_x,float pos_y);

	void renderEnemies(RenderTarget& target);
	void initEnemies();

	void initVariables();

	void update(RenderTarget& target, int level);
	void render(RenderTarget* target);

	const FloatRect getBounds() const;
};

