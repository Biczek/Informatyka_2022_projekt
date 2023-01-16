#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>
#include<iostream>
#include<vector>


using namespace sf;
using namespace std;


class Player
{
private:

	float attackCooldown;
	float attackCooldownMax = 100.f;

	Text text;
	Font font;

	Texture texture;

	void initTexture();
	void initSprite();

public:

	Sprite sprite;

	const Vector2f& getPos() const;

	Player();
	void updateAttack();
	void updatePlayer();
	const bool canAttack();
	const FloatRect getBounds() const;

	void moveSprite(const float dirX, const float dirY, const float velocity);
	void initVariables();
	void renderPlayer(RenderTarget& target);
	void basicPos(RenderTarget& target);

	void rotatePlayer(float Angle)
	{
		sprite.setRotation(Angle);
	}
};



