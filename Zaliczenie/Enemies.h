#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>
#include<vector>

using namespace sf;
using namespace std;

class Enemies
{
private:

	int max_enemies = 10;
	int timer = 0;
	int timer_max = 5;
	bool direction = false;

public:
	
	std::vector<sf::ConvexShape> enemies;
	sf::ConvexShape enemy;

	Enemies();
	void renderEnemies(RenderTarget& target);
	void initEnemies();
	void updateEnemies(RenderTarget& target);
	void spawnEnemies(RenderTarget& target);

	const sf::ConvexShape& getShape() const;
};

