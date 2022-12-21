/* Gra wedle scenariusza 1 */

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>

using namespace sf;


float velocity = 5.f;


class Enemies
{
private:
	int max_enemies = 10;
	int timer = 0;
	int timer_max = 5;
	std::vector<sf::ConvexShape> enemies;
	sf::ConvexShape enemy;

public:
	Enemies();
	void renderEnemies(RenderTarget &target);
	void initEnemies();
	void updateEnemies(RenderTarget &target);
	void spawnEnemies(RenderTarget &target);
};

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
	enemy.setFillColor(Color::Yellow);
	enemy.setOrigin(15.f, 20.f);
	enemy.rotate(180);
	enemy.setPosition(50.f, 50.f);
	enemy.setScale(Vector2f(2.f, 2.f));
}
void Enemies::renderEnemies(RenderTarget &target)
{
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}
void Enemies::spawnEnemies(RenderTarget &target)
{
	enemy.setPosition(static_cast<float>(rand() % static_cast<int>(target.getSize().x) - 30.f), 0.f);

	//Randomize enemy type

	int type = rand() % 5;

	switch (type)
	{
	case 0:
		this->enemy.setScale(2.f,2.f);
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
	
};

class Player
{
private:
	
	sf::RectangleShape Gracz;

public:
	Player();

	void initPlayer();
	void updatePlayer(RenderTarget &target);
	void renderPlayer(RenderTarget &target);
};

Player::Player()
{
	initPlayer();
};

void Player::initPlayer()
{
	Gracz.setSize(Vector2f(100.f, 100.f));
	Gracz.setFillColor(Color::Red);
	Gracz.setOrigin(50.f, 50.f);
	Gracz.setPosition(500.f, 600.f);
	

};

void Player::updatePlayer(RenderTarget &target)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && Gracz.getPosition().x > 0 + Gracz.getSize().x / 2)
	{
		Gracz.move(-velocity, 0.f);

	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && Gracz.getPosition().x + Gracz.getSize().x / 2 < target.getSize().x)
	{
		Gracz.move(velocity, 0.f);

	}
	if (Keyboard::isKeyPressed(Keyboard::W) && Gracz.getPosition().y > 0 + Gracz.getSize().y / 2)
	{
		Gracz.move(0.f, -velocity);

	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && Gracz.getPosition().y + Gracz.getSize().y / 2 < target.getSize().y)
	{
		Gracz.move(0.f, velocity);
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		Gracz.setFillColor(Color::Blue);

	}
	else
	{
		Gracz.setFillColor(Color::Red);
	}
};

void Player::renderPlayer(RenderTarget &target)
{
	target.draw(Gracz);
};


int main()
{
	srand(static_cast<unsigned>(time(0)));
	

	
	RenderWindow window(VideoMode(1000, 800), "Game");
	window.setFramerateLimit(60);


	/*
	CircleShape bullet;
	bullet.setRadius(10.f);
	bullet.setFillColor(Color::Blue);
	bullet.setOutlineThickness(5.f);
	bullet.setOutlineColor(Color::Cyan);
	bullet.setOrigin(bullet.getRadius(), bullet.getRadius());
	bullet.setPosition(window.getSize().x / 2, window.getSize().y / 2);*/


	Enemies Enemies;
	Event event;
	Player player;

	while (window.isOpen())
	{
		

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

		}


		//Update
		window.clear();

		player.updatePlayer(window);
		Enemies.updateEnemies(window);

		//Draw
		player.renderPlayer(window);
		Enemies.renderEnemies(window);
		window.display();
		
	}

	return 0;
}







