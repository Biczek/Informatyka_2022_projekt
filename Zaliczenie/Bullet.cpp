#include "Bullet.h"




void Bullet::spawnBullet(float x, float y)
{
	bullet.setFillColor(Color::Red);
	bullet.setRadius(20.f);
	bullet.setOrigin(bullet.getRadius() / 2, bullet.getRadius() / 2);
	bullet.setPosition(x, y);

	bullets.push_back(bullet);
}

Bullet::Bullet()
{
}

void Bullet::updateBullet(float x, float y)
{
	if (bullets.size() <= max_bullets)
	{
		if (timer < max_timer)
		{
			spawnBullet(x,y);
			timer = 0;
		}
		else
		{
			timer++;
		}
	};
	

	
}
void Bullet::renderBullet(RenderTarget& target)
{
	for (auto& e : this->bullets)
	{
		target.draw(e);
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(0.f, -5.f); // velocity of bullets
	}
}