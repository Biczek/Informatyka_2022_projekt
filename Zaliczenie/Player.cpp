#include "Player.h"

Player::Player()
{
	initVariables();
	initTexture();
	initSprite();

}
void Player::initTexture()
{
	if (!this->texture.loadFromFile("Texture/ship.png"))
	{
		cout << "ERROR::LOAD_TEXTURE::SHIP"<<"\n";
	}
}
void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(0.1f,0.1f);

}
void Player::initVariables()
{
	
}
;

void Player::moveSprite(const float dirX, const float dirY, const float velocity)
{
	sprite.move(dirX * velocity, dirY * velocity);
}
void Player::updatePlayer(RenderTarget& target, float velocity)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		moveSprite(-1.f, 0.f, velocity);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		moveSprite(1.f, 0.f, velocity);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		moveSprite(0.f, -1.f, velocity);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		moveSprite(0.f, 1.f, velocity);
	}


	if (Mouse::isButtonPressed(Mouse::Left))
	{

	}
};

void Player::renderPlayer(RenderTarget& target)
{
	target.draw(sprite);
}






