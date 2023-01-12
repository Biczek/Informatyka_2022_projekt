#pragma once
#include "Player.h"


class Enemies
{
private:

	float velocity;
	bool down;
	float position_x;
	float position_y;

	bool new_position;
	int position;

public:
	ConvexShape enemy;

	Enemies(float pos_x, float pos_y);

	void initEnemies();
	void initVariables();

	void update(RenderTarget& target);
	void render(RenderTarget* target);
	const FloatRect getBounds() const;

	void choseLevel(int level);
	
};

