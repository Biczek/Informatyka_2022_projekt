#include "Confirm.h"

Confirm::Confirm(float width, float height)
{
	if (!font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		cout << "No font is here";
	}

	//Question
	ConfirmMenu[0].setFont(font);
	ConfirmMenu[0].setFillColor(Color::White);
	ConfirmMenu[0].setString("Are you sure you want to close the game?");
	ConfirmMenu[0].setCharacterSize(37);
	ConfirmMenu[0].setPosition(30,50);
	//Yes
	ConfirmMenu[1].setFont(font);
	ConfirmMenu[1].setFillColor(Color::White);
	ConfirmMenu[1].setString("YES");
	ConfirmMenu[1].setCharacterSize(70);
	ConfirmMenu[1].setPosition(200, 100);
	//No
	ConfirmMenu[2].setFont(font);
	ConfirmMenu[2].setFillColor(Color::White);
	ConfirmMenu[2].setString("NO");
	ConfirmMenu[2].setCharacterSize(70);
	ConfirmMenu[2].setPosition(300, 100);

	ConfirmMenuSelected = 1;
	ConfirmMenu[ConfirmMenuSelected].setFillColor(Color::Blue);
}

Confirm::~Confirm()
{
}

void Confirm::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_confirm_menu; i++)
	{
		window.draw(ConfirmMenu[i]);
	}
}

void Confirm::MoveUp()
{
	
	if (ConfirmMenuSelected > 1)
	{
		ConfirmMenu[ConfirmMenuSelected].setFillColor(Color::White);


		ConfirmMenuSelected--;
		if (ConfirmMenuSelected == 0)
		{
			ConfirmMenuSelected = 2;
		}
		ConfirmMenu[ConfirmMenuSelected].setFillColor(Color::Blue);
	}
}

void Confirm::MoveDown()
{
	if (ConfirmMenuSelected < Max_confirm_menu)
	{
		ConfirmMenu[ConfirmMenuSelected].setFillColor(Color::White);
		ConfirmMenuSelected++;
		if (ConfirmMenuSelected == 3)
		{
			ConfirmMenuSelected = 1;
		}
		ConfirmMenu[ConfirmMenuSelected].setFillColor(Color::Blue);
	}
}

bool Confirm::ReturnMenuSelected()
{
	if (ConfirmMenuSelected == 1)
	{
		return true;
	}
	if (ConfirmMenuSelected == 2)
	{
		return false;
	}
}
