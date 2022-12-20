#pragma once

#include <ctime>
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Gra
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;

	void initVariables();
	void initWindow();

public:
	Gra();
	~Gra();

	void renderWindow();
	void updateWindow();
};

