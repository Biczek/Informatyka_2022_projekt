#include "Game.h"

Game::Game(RenderWindow& window)
{
	initFont();
	initText();
	initVariables();
	player.basicPos(window);
}

void Game::update(RenderTarget& target, float velocity)
{
		updateText();
		updateColision();
		input(target);
		updateBullet();
		updateEnemies(target);
		updateColision();
		player.updatePlayer();

		if(health <= 0)
		{
			play = false;
		}
}

void Game::updateColision()
{

	for (auto* Enemy : enemies)
	{

		if (Enemy->getBounds().intersects(player.getBounds()) && touched == false)
		{
			health -= demage;
			touched = true;
		}
		else
		{
			delay++;
		}

		if (delay >= 10000)
		{
			touched = false;
			delay = 0;

		}
		
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

void Game::updateEnemies(RenderTarget& target)
{
	unsigned counter_2 = 0;
	bool shooted = false;

	for (auto* enemy : enemies)
	{
		enemy->update(target);
		enemy->choseLevel(level);
		levelChoosen(level);

		for (auto Bullet : bullets)
		{
			if (enemy->getBounds().intersects(Bullet->getBonds()))
			{
				shooted = true;

			}
		}
		if (shooted)
		{

			delete enemies.at(counter_2);
			enemies.erase(enemies.begin() + counter_2);
			--counter_2;
			points += 1;
			enemies_amout_max += 1;
			
		}
		counter_2++;
		shooted = false;
	}
	if (timer >= timer_max)
	{

		if (enemies_amout < enemies_amout_max)
		{
			enemies.push_back(new Enemies(rand() % 1000, 20.f));
			enemies_amout++;
		}
		timer = 0;

	}
	timer++;
		

}
void Game::input(RenderTarget& target)
{
	if (Keyboard::isKeyPressed(Keyboard::Left) && (player.getPos().x > 0) )
	{
		player.moveSprite(-1.f, 0.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && ((player.getPos().x + player.getBounds().width )< target.getSize().x ))
	{
		player.moveSprite(1.f, 0.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) && (player.getPos().y > 0))
	{
		player.moveSprite(0.f, -1.f, velocityPlayer);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && ((player.getPos().y + player.getBounds().height)< target.getSize().y))
	{
		player.moveSprite(0.f, 1.f, velocityPlayer);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && player.canAttack())
	{
		bullets.push_back(new Bullet(player.getPos().x + 30.f, player.getPos().y, 10.f));
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
	text.setCharacterSize(40);
	text.setOutlineColor(Color::Blue);
	text.setOutlineThickness(2.f);
	text.setFillColor(sf::Color::White);
	text.setString("NONE");

	text_2.setFont(this->font);
	text_2.setCharacterSize(30);
	text_2.setOutlineColor(Color::Blue);
	text_2.setOutlineThickness(2.f);
	text_2.setFillColor(sf::Color::White);
	text_2.setPosition(860.f, 10.f);
	text_2.setString("F1 - HELP");

	game_over.setFont(this->font);
	game_over.setCharacterSize(100);
	game_over.setOutlineThickness(2.f);
	game_over.setOutlineColor(Color::Red);
	game_over.setFillColor(sf::Color::Red);
	game_over.setString("GAME OVER");
	game_over.setPosition(250.f,300.f);
}

void Game::initVariables()
{

	health = 10;
	points = 0;
	touched = false;
	delay = 0;
	play = true;
	demage = 1;
	level = 1;
	timer = 0;
	timer_max = 200;

	enemies_amout = 0;
	enemies_amout_max = 10;

}

void Game::levelChoosen(int level)
{
	switch (level)
	{
	case(1):
		demage = 1;
		break;

	case(2):
		demage = 1;
		break;

	case(3):
		demage = 1;
		break;

	case(4):
		demage = 2;
		break;
	}
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
	target.draw(text_2);
}
void Game::renderGameOver(RenderTarget& target)
{
	target.draw(game_over);
}