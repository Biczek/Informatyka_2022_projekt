#pragma once
#include "Player.h"


class Enemies
{
private:

	int hp;
	int hp_max;
	int demage;

	float velocity;


public:
	ConvexShape enemy;

	Enemies(float pos_x, float pos_y);

	void initEnemies();
	void initVariables();

	void update();
	void enemys_level(int level);
	void render(RenderTarget* target);
	const FloatRect getBounds() const;
};

