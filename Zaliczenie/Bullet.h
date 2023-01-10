#pragma once
#include"Player.h"


class Bullet
{
private:

	Sprite shape;
	Texture texture;
	Vector2f Position;
	float movementspeed;

public:
	Bullet( float pos_x, float pos_y, float Movementspeed);

	const FloatRect getBounds() const;

	void initTexture();
	void update();
	void render(RenderTarget* target);
};

