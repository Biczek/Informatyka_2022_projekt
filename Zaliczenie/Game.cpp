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
	player.updatePlayer(target, velocity);
	updateText();
	updateColision();
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
		/*if (Enemies.enemies[i].getGlobalBounds().intersects(player.Bullet.getGlobalBounds()))
		{
			hit_bullet = true;
			Enemies.enemies.erase(this->Enemies.enemies.begin() + i);
		}*/
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

void Game::render(RenderTarget& target)
{
	Enemies.renderEnemies(target);
	player.renderPlayer(target);
	renderText(target);
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