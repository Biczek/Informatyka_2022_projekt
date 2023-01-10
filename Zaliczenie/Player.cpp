#include "Player.h"

const Vector2f& Player::getPos() const
{
	return sprite.getPosition();
}

Player::Player()
{
	initVariables();
	initTexture();
	initSprite();

}
void Player::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
	{
		attackCooldown += 1.f;
	}
}
void Player::updatePlayer()
{
	updateAttack();
}
const bool Player::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}
	return false;
	
}
const FloatRect Player::getBounds() const
{
	return sprite.getGlobalBounds();
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

void Player::renderPlayer(RenderTarget& target)
{
	target.draw(sprite);
}






