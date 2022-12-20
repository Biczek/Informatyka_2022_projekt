#include "Gra.h"

void Gra::initVariables()
{

	this->endGame = false;
	
}

void Gra::initWindow()
{
	this->videoMode = sf::VideoMode(1000, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Gra", sf::Style::Close | sf::Style::Titlebar );
}

//Constructor and destructor

Gra::Gra()
{
	this->initWindow();
	this->initVariables();
}

Gra::~Gra()
{

}

const bool Gra::running() const
{
	return this->window->isOpen();
}

void Gra::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::F1)
			{

			}
		}
	}
}



//Funkcje 

void Gra::render()
{
	this->window->clear();


	this->window->display();
}

void Gra::update()
{
	this->pollEvents();
}
