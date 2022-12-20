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
	sf::Event event;
	

	void initVariables();
	void initWindow();

public:
	Gra();
	~Gra();

	const bool running() const;
	void pollEvents();

	void render();
	void update();
};

