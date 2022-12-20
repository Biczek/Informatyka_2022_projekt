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



//Funkcje 

void Gra::renderWindow()
{

}

void Gra::updateWindow()
{

}
