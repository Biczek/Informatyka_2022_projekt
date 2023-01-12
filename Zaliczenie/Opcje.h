#pragma once
#include "mainMenu.h"
#include<sstream>
#include<iostream>

#define Max_option_menu 6

class Opcje
{
private:

	int level = 1;
	Font font;
	Text text;
	Text OptionsMenu[Max_option_menu];


	const char* Buttons[6] = { "	Choose level:" , "  Press 1 to level 1", "  Press 2 to level 2",
		"  Press 3 to level 3", "  Press 4 to level 4", "Press Escape to Exit" };
	const int offsetButtons = 100;
public:
	Opcje(float width, float height);
	void initText();
	void updateText();
	void renderText(RenderWindow& window);

	void update(int LEVEL);
	void draw(RenderWindow& window);

};

