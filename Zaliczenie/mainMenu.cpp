#include "mainMenu.h"

mainMenu::mainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here";
	}

	for (int i = 0; i <= 3;i++)
	{
		MainMenu[i].setFillColor(Color::White);
		MainMenu[i].setFont(font);
		MainMenu[i].setString(Buttons[i]);
		MainMenu[i].setCharacterSize(70);
		MainMenu[i].setPosition(400, 200 + offsetButtons * i);
	}
	MainMenuSelected = 0;
}
mainMenu::~mainMenu()
{

}
//Draw MainMenu
void mainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(MainMenu[i]);
	}
}
//MoveUp
void mainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		MainMenu[MainMenuSelected].setFillColor(Color::White);


		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		MainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}
//MoveDown
void mainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		MainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		MainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}