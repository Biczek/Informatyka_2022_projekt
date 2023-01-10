#include "Game.h"

Game::Game()
{
	initFont();
	initText();
	initVariables();
}

void Game::update(RenderTarget& target, float velocity)
{
	Enemies.updateEnemies(target);
	updateText();
	updateColision();
	input();
	updateBullet();
	player.updatePlayer();

}

void Game::updateColision()
{
	bool hit_player = false;
	bool hit_bullet = false;

	for (int i = 0; i <= Enemies.enemies.size();i++)
	{
		if (Enemies.enemies[i].getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
		{
			hit_player = true;
		
		}
	}

	if (hit_player)
	{
		health -= 1;
	}
	if (hit_bullet)
	{
		points += 1;
	}
}

void Game::updateBullet()
{
	unsigned counter = 0;
	for (auto* bullet : bullets)
	{
		bullet->update();

		//Bullet culling top of the screen
		if (bullet->getBounds().top + bullet->getBounds().height < 0)
		{
			//delete bullet
			delete bullets.at(counter);
			bullets.erase(bullets.begin() + counter);
			--counter;
		}
		counter++;
	}
}

void Game::input()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.moveSprite(-1.f, 0.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.moveSprite(1.f, 0.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player.moveSprite(0.f, -1.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player.moveSprite(0.f, 1.f, velocityPlayer);
	}

	if (Mouse::isButtonPressed(Mouse::Left) && player.canAttack())
	{
		bullets.push_back(new Bullet(player.getPos().x, player.getPos().y, 10.f));
	}
}



void Game::render(RenderTarget& target)
{
	Enemies.renderEnemies(target);
	player.renderPlayer(target);
	renderText(target);

	for (auto *bullet : bullets)
	{
		bullet->render(&target);
	}
}

void Game::initFont()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here";
	}
}

void Game::initText()
{
	text.setFont(this->font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setString("NONE");
}
void Game::initVariables()
{
	health = 20;
	points = 0;
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << points << "\n"
		<< "Health: " << health << "\n";

	text.setString(ss.str());

}
void Game::renderText(RenderTarget& target)
{
	target.draw(text);
}