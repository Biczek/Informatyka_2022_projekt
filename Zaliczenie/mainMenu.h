#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player.h"

using namespace std;
using namespace sf;

#define Max_main_menu 4

class mainMenu
{
private:
	int MainMenuSelected;
	unsigned timer = 0;
	unsigned timer_max = 2000;

	float velocityPlayer = 0.3f;
	float x = -1.f;
	float y = 0.f;

	Font font;
	Text MainMenu[Max_main_menu];
	Text Title;

	Player player;

	const char* Buttons[4] = { "  Play", "Options", "Ranking" , "  Exit" };
	const int offsetButtons = 150;


public:
	mainMenu(RenderTarget& target);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();


	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~mainMenu();
	
};

