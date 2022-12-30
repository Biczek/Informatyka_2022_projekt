#include "Player.h"

Player::Player()
{
	initPlayer();
	initBullet();
	initVariables();
}
void Player::initVariables()
{
	shot = false;
}
;

void Player::initPlayer()
{
	Gracz.setSize(Vector2f(100.f, 100.f));
	Gracz.setFillColor(Color::Red);
	Gracz.setOrigin(50.f, 50.f);
	Gracz.setPosition(500.f, 600.f);


};

void Player::updatePlayer(RenderTarget& target, float velocity)
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
		shot = true;
		Bullet.setPosition(Gracz.getPosition().x, Gracz.getPosition().y);
	}
	else
	{
		Gracz.setFillColor(Color::Red);
	}
	updateBullet(target);
};

void Player::renderPlayer(RenderTarget& target)
{
	target.draw(Gracz);
}
void Player::initBullet()
{
	Bullet.setFillColor(Color::Red);
	Bullet.setRadius(20.f);
	Bullet.setOrigin(Bullet.getRadius() / 2, Bullet.getRadius()/2);
	
}
void Player::updateBullet(RenderTarget& target)
{
	

	if (Bullet.getPosition().y > 0 || shot == true)
	{
		Bullet.move(0.f, -5.f);

		if (Bullet.getPosition().y == 0)
		{
			shot = false;
		}
	}
}
void Player::renderBullet(RenderTarget& target)
{
	target.draw(Bullet);
}
;