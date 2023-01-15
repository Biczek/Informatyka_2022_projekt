#include "Help.h"

Help::Help(float width, float height)
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here";
	}

	for (int i = 0; i < Max_help_menu; i++)
	{
		HelpMenu[i].setFillColor(Color::White);
		HelpMenu[i].setFont(font);
		HelpMenu[i].setString(Buttons[i]);
		HelpMenu[i].setCharacterSize(40);
		HelpMenu[i].setOutlineThickness(3.f);
		HelpMenu[i].setPosition(125, 100 + Offset * i);
	}
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