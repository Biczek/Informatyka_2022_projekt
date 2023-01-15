#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>

#include"Enemies.h"
#include"Player.h"
#include"Bullet.h"

class Game
{
private:
	//playerVariables
	int health;
	int points;
	bool touched;
	bool play;
	unsigned timer;
	unsigned timer_max;

	int level;

	//enemyVariables
	int demage;

	unsigned delay;

	int enemies_amout;
	int enemies_amout_max;


	//Bullets
	vector<Bullet*> bullets;

	//Enemys
	vector<Enemies*> enemies;

	//Player
	Player player;

	//Text&Font
	Font font;
	Text text;
	Text text_2;
	Text game_over;
	
	//Speed
	float velocityPlayer = 1.f;

public:
	
	Game(RenderWindow& window);

	//Update
	void update(RenderTarget& target, float velocity);
	void updateColision();
	void updateBullet();

	void updateEnemies(RenderTarget& target);
	void input(RenderTarget& target);
	
	//Render
	void render(RenderTarget& target);

	//Text & Variables
	void updateText();
	void renderText(RenderTarget& target);
	void renderGameOver(RenderTarget& target);
	
	//Chose enemy level
	void setLevel(int LEVEL)
	{
		level = LEVEL;
	}
	void levelChoosen(int level);

	//void enemyLevel(int level);

	void initFont();
	void initText();

	void initVariables();

	bool endGame()
	{
		return play;
	}
	int points_return()
	{
		return points;
	}
	
};

