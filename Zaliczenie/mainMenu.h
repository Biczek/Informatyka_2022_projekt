#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4

class mainMenu
{
private:
	int MainMenuSelected;
	Font font;
	Text MainMenu[Max_main_menu];
	const char* Buttons[4] = { "Play", "Options", "About" , "Exit" };
	const int offsetButtons = 100;


public:
	mainMenu(float width, float height);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MainMenuPressed()
	{
		return MainMenuSelected;
	}
	~mainMenu();

};

