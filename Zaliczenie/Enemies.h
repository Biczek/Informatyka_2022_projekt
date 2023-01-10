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

class Enemies
{
private:

	int timer = 0;
	int timer_max = 5;
	int max_enemies;

	float velocity;

public:
	
	std::vector<sf::ConvexShape> enemies;
	sf::ConvexShape enemy;

	Enemies();
	void renderEnemies(RenderTarget& target);
	void initEnemies();
	void updateEnemies(RenderTarget& target);
	void spawnEnemies(RenderTarget& target);
	void moveEnemie(int numeber_of_enemy, const float velocity, const float dirX, const float dirY);


	const sf::ConvexShape& getShape() const;
};

