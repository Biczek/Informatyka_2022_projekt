#include "Enemies.h"

Enemies::Enemies()
{
	initEnemies();
};
void Enemies::initEnemies()
{

	enemy.setPointCount(6);

	enemy.setPoint(0, Vector2f(10.f, 0.f));
	enemy.setPoint(1, Vector2f(20.f, 15.f));
	enemy.setPoint(2, Vector2f(15.f, 40.f));
	enemy.setPoint(3, Vector2f(10.f, 20.f));
	enemy.setPoint(4, Vector2f(5.f, 40.f));
	enemy.setPoint(5, Vector2f(0.f, 15.f));

	enemy.setOrigin(15.f, 20.f);
	enemy.rotate(180);
	enemy.setPosition(50.f, 50.f);
	enemy.setScale(Vector2f(2.f, 2.f));
}
void Enemies::renderEnemies(RenderTarget& target)
{
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}
void Enemies::spawnEnemies(RenderTarget& target)
{
	enemy.setPosition(static_cast<float>(rand() % static_cast<int>(target.getSize().x) - 15.f), static_cast<float>(rand() % static_cast<int>(100)));

	//Randomize enemy type

	int type = rand() % 5;

	switch (type)
	{
	case 0:
		this->enemy.setScale(2.f, 2.f);
		this->enemy.setFillColor(sf::Color::Magenta);

		break;
	case 1:
		this->enemy.setScale(2.f, 2.f);
		this->enemy.setFillColor(sf::Color::Blue);

		break;
	case 2:
		this->enemy.setScale(2.f, 2.f);
		this->enemy.setFillColor(sf::Color::Cyan);

		break;
	case 3:
		this->enemy.setScale(2.f, 2.f);
		this->enemy.setFillColor(sf::Color::Red);

		break;
	case 4:
		this->enemy.setScale(2.f, 2.f);
		this->enemy.setFillColor(sf::Color::Green);

		break;

	default:
		this->enemy.setScale(2.f, 2.f);
		this->enemy.setFillColor(sf::Color::Yellow);
		break;
	}

	//Spawn the enemy
	this->enemies.push_back(this->enemy);
}


const sf::ConvexShape& Enemies::getShape() const
{
	return enemy;
}


void Enemies::updateEnemies(RenderTarget& target)
{
	if (enemies.size() <= max_enemies)
	{
		if (timer < timer_max)
		{
			spawnEnemies(target);
			timer = 0;
		}
		else
		{
			timer++;
		}
	};

	for (int i = 0; i < enemies.size(); i++)
	{
		if (direction == false)
		{
			enemies[i].move(0.f, 1.f); //velocity down

			if (enemies[i].getPosition().y >= target.getSize().y)
			{
				direction = true;

			};

		}
		if (direction == true)
		{
			enemies[i].move(0.f, -5.f); //velocity up

			if (enemies[i].getPosition().y <= 0)
			{
				direction = false;

			}
		}
	}
};