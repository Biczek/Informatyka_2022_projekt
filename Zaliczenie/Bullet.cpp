#include "Bullet.h"



Bullet::Bullet( float pos_x, float pos_y, float Movementspeed)
{
	initTexture();
	shape.setTexture(texture);
	movementspeed = Movementspeed;
	shape.setPosition(pos_x, pos_y);
}

const FloatRect Bullet::getBounds() const
{
	return shape.getGlobalBounds();
}

void Bullet::initTexture()
{
	if (!this->texture.loadFromFile("Texture/bullet.PNG"))
	{
		cout << "ERROR::LOAD_TEXTURE::BULLET" << "\n";
	}
}

void Bullet::update()
{
	shape.move(0.f,-0.1f*movementspeed);

}

void Bullet::render(RenderTarget* target)
{
	target->draw(shape);
}

