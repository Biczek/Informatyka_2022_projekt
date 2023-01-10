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

	

	vector<Bullet*> bullets;


	Enemies Enemies;
	Player player;
	Font font;
	Text text;
	
	//Speed

	float velocityPlayer = 1.f;

public:
	
	Game();

	//Update
	void update(RenderTarget& target, float velocity);
	void updateColision();
	void updateBullet();
	void input();
	
	//Render
	void render(RenderTarget& target);

	//Text & Variables
	void updateText();
	void renderText(RenderTarget& target);

	void initFont();
	void initText();

	void initVariables();

};

