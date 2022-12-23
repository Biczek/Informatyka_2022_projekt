#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>

using namespace sf;

class Enemies
{
private:
	int max_enemies = 10;
	int timer = 0;
	int timer_max = 5;
	std::vector<sf::ConvexShape> enemies;
	sf::ConvexShape enemy;
	bool direction = false;

public:
	Enemies();
	void renderEnemies(RenderTarget& target);
	void initEnemies();
	void updateEnemies(RenderTarget& target);
	void spawnEnemies(RenderTarget& target);
};

