#include "Help.h"

Help::Help(float width, float height)
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here";
	}

	HelpMenu[0].setFont(font);
	HelpMenu[0].setFillColor(Color::White);
	HelpMenu[0].setString("Simple instruction");
	HelpMenu[0].setCharacterSize(30);
	HelpMenu[0].setOrigin(50,10);
	HelpMenu[0].setPosition(width/2, 20);
	
	HelpMenu[1].setFont(font);
	HelpMenu[1].setFillColor(Color::White);
	HelpMenu[1].setString("A - move left");
	HelpMenu[1].setCharacterSize(30);
	HelpMenu[1].setOrigin(50, 10);
	HelpMenu[1].setPosition(width / 2, 50);
	
	HelpMenu[2].setFont(font);
	HelpMenu[2].setFillColor(Color::White);
	HelpMenu[2].setString("D - move right");
	HelpMenu[2].setCharacterSize(30);
	HelpMenu[2].setOrigin(50, 10);
	HelpMenu[2].setPosition(width / 2, 80);

	HelpMenu[3].setFont(font);
	HelpMenu[3].setFillColor(Color::White);
	HelpMenu[3].setString("W - move up");
	HelpMenu[3].setCharacterSize(30);
	HelpMenu[3].setOrigin(50, 10);
	HelpMenu[3].setPosition(width / 2, 110);

	HelpMenu[4].setFont(font);
	HelpMenu[4].setFillColor(Color::White);
	HelpMenu[4].setString("S - move down");
	HelpMenu[4].setCharacterSize(30);
	HelpMenu[4].setOrigin(50, 10);
	HelpMenu[4].setPosition(width / 2, 140);
}

Help::~Help()
{
}

void Help::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_help_menu; i++)
	{
		window.draw(HelpMenu[i]);
	}
}