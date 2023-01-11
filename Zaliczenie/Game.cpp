#include "Game.h"

Game::Game()
{
	initFont();
	initText();
	initVariables();
}

void Game::update(RenderTarget& target, float velocity)
{
	updateText();
	updateColision();
	input(target);
	updateBullet();
	updateEnemies();
	player.updatePlayer();

}

void Game::updateColision()
{
	//Make colision here

	bool hit_player = false;
	bool hit_bullet = false;

	
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

void Game::updateEnemies()
{
	for (auto* enemy : enemies)
	{
		enemy->enemys_level(1);//do poprawy
		enemy->update();
	}

	if (enemies_amout < enemies_amout_max)
	{
		enemies.push_back(new Enemies(rand() % 1000, rand() % 400));
		enemies_amout++;
	}
	

}
void Game::input(RenderTarget& target)
{
	if (Keyboard::isKeyPressed(Keyboard::A) && (player.getPos().x > 0) )
	{
		player.moveSprite(-1.f, 0.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && ((player.getPos().x + player.getBounds().width )< target.getSize().x ))
	{
		player.moveSprite(1.f, 0.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::W) && (player.getPos().y > 0))
	{
		player.moveSprite(0.f, -1.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && ((player.getPos().y + player.getBounds().height)< target.getSize().y))
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
	player.renderPlayer(target);
	renderText(target);

	for (auto *enemy : enemies)
	{
		enemy->render(&target);
	}


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

	enemies_amout = 0;
	enemies_amout_max = 3;

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