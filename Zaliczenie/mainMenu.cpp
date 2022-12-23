#include "mainMenu.h"

mainMenu::mainMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here";
	}

	//Play
	MainMenu[0].setFont(font);
	MainMenu[0].setFillColor(Color::White);
	MainMenu[0].setString("Play");
	MainMenu[0].setCharacterSize(70);
	MainMenu[0].setPosition(400, 200);
	//Options
	MainMenu[1].setFont(font);
	MainMenu[1].setFillColor(Color::White);
	MainMenu[1].setString("Options");
	MainMenu[1].setCharacterSize(70);
	MainMenu[1].setPosition(400, 300);
	//About
	MainMenu[2].setFont(font);
	MainMenu[2].setFillColor(Color::White);
	MainMenu[2].setString("About");
	MainMenu[2].setCharacterSize(70);
	MainMenu[2].setPosition(400, 400);
	//Exite
	MainMenu[3].setFont(font);
	MainMenu[3].setFillColor(Color::White);
	MainMenu[3].setString("Exit");
	MainMenu[3].setCharacterSize(70);
	MainMenu[3].setPosition(400, 500);

	MainMenuSelected = -1;
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