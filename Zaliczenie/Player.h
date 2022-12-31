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

	Text text;
	Font font;

	Texture texture;

	void initTexture();
	void initSprite();

public:

	Sprite sprite;

	Player();

	void moveSprite(const float dirX, const float dirY, const float velocity);
	void initVariables();
	void updatePlayer(RenderTarget& target, float velocity);
	void renderPlayer(RenderTarget& target);
};



