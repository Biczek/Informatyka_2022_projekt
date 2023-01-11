#include "Enemies.h"

Enemies::Enemies(float pos_x, float pos_y)
{
	initEnemies();
	initVariables();
	enemy.setPosition(pos_x, pos_x);
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

const FloatRect Enemies::getBounds() const
{
	return enemy.getGlobalBounds();
}




void Enemies::update(RenderTarget& target)
{
	
}

void Enemies::initVariables()
{

}

void Enemies::render(RenderTarget* target)
{
	target->draw(enemy);
}

void Enemies::enemys_level(int level)
{
	switch (level)
	{
	case(1):
		enemy.setFillColor(Color::Green);
		enemy.setScale(2.f, 2.f);

		velocity = 1.f;
		hp_max = 1;
		demage = 1;
	case(2):
		enemy.setFillColor(Color::Yellow);
		enemy.setScale(1.f, 1.f);

		velocity = 1.f;
		hp_max = 2;
		demage = 1;
	case(3):
		enemy.setFillColor(Color::Red);
		enemy.setScale(1.f, 1.f);

		velocity = 2.f;
		hp_max = 2;
		demage = 2;

	default:
		enemy.setFillColor(Color::Blue);
		enemy.setScale(2.f, 2.f);

		velocity = 1.f;
		hp_max = 1;
		demage = 1;

		break;
	}
}