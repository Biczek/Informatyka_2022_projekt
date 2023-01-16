#include "mainMenu.h"

mainMenu::mainMenu(RenderTarget& target)
{
	if (!font.loadFromFile("Fonts/The Led Display St.ttf"))
	{
		cout << "No font is here";
	}

	for (int i = 0; i <= 3;i++)
	{
		MainMenu[i].setFillColor(Color::White);
		MainMenu[i].setFont(font);
		MainMenu[i].setString(Buttons[i]);
		MainMenu[i].setCharacterSize(70);
		MainMenu[i].setOutlineThickness(7.f);
		MainMenu[i].setPosition(300, 200 + offsetButtons * i);
	}

	MainMenuSelected = 0;
	MainMenu[MainMenuSelected].setFillColor(Color::Blue);

	Title.setFont(font);
	Title.setCharacterSize(80);
	Title.setOutlineThickness(10.f);
	Title.setPosition(100.f, 50.f);
	Title.setString("SPACE INVADERS");

	player.basicPos(target);
	player.rotatePlayer(-90);
}
mainMenu::~mainMenu()
{

}
//Draw MainMenu
void mainMenu::draw(RenderWindow& window)
{
	player.renderPlayer(window);

	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(MainMenu[i]);
	}
	
	if (timer >= timer_max)
	{
		Title.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
		timer = 0;
	}
	window.draw(Title);
	timer++;

	
	if (player.getPos().x <= 100.f)
	{
		y = 0.f;
		x = 1.f;
		player.rotatePlayer(90);
	}
	if (player.getPos().x + player.getBounds().width >= window.getSize().x - 50.f)
	{
		y = 0.f;
		x = -1.f;
		player.rotatePlayer(270);
	}
	

	player.moveSprite(x, y, velocityPlayer);
	
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



