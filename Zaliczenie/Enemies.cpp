#include "Enemies.h"

Enemies::Enemies(float pos_x, float pos_y)
{
	initEnemies();
	initVariables();
	enemy.setPosition(pos_x, 20.f);
	position_x = pos_x;
	position_y = pos_y;
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
	enemy.setScale(2.f, 2.f);
	
}

const FloatRect Enemies::getBounds() const
{
	return enemy.getGlobalBounds();
}

void Enemies::choseLevel(int level)
{
	switch (level)
	{
	case(1):
		enemy.setFillColor(Color::Blue);
		velocity = 0.2f;
		break;

	case(2):
		enemy.setFillColor(Color::Cyan);
		velocity = 0.5f;
		break;
	case(3):
		enemy.setFillColor(Color::Yellow);
		velocity = 0.7f;
		break;
	case(4):
		enemy.setFillColor(Color::Red);
		velocity = 1.f;
		break;
	}

}






void Enemies::update(RenderTarget& target)
{
	
		if (down == true)
		{
			enemy.move(0.f, 1.f*velocity);

			if (enemy.getPosition().y >= target.getSize().y)
			{
				down = false;
			}
		}

		if (down == false)
		{
			if (position_x >= position)
			{
				if (position_x != 0.f)
				{
					enemy.move(-0.5f, -1.f);
					position_x -= 0.5f;
				}
				else
				{
					enemy.move(0.f, -1.f);
				}
			}

			if (position_x < position)
			{
				if (position_x != target.getSize().x)
				{
					enemy.move(0.5f, -1.f);
					position_x += 0.5f;
				}
				else
				{
					enemy.move(0.f, -1.f);
				}
			}


			if (enemy.getPosition().y <= 0)
			{
				down = true;
				position = rand() % target.getSize().x;

			}
		}
}

void Enemies::initVariables()
{
	down = true;
	new_position = false;
	position = rand() % 600;
}

void Enemies::render(RenderTarget* target)
{
	target->draw(enemy);
}

