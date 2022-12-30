#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>
#include<iostream>
#include<vector>

#include"Enemies.h"
#include"Player.h"
#include"Bullet.h"

class Game
{
private:

	int health;
	int points;

	Enemies Enemies;
	Player player;
	Font font;
	Text text;


public:
	
	Game();

	//Update
	void update(RenderTarget& target, float velocity);
	void updateColision();

	//Render
	void render(RenderTarget& target);

	//Text & Variables
	void updateText();
	void renderText(RenderTarget& target);

	void initFont();
	void initText();

	void initVariables();


};

