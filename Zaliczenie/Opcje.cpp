#include "Opcje.h"


Opcje::Opcje(float width, float height)
{
	initText();

	if (!font.loadFromFile("Fonts/The Led Display St.ttf"))
	{
		cout << "No font is here";
	}

	for (int i = 0; i < Max_option_menu; i++)
	{
		OptionsMenu[i].setFillColor(Color::White);
		OptionsMenu[i].setFont(font);
		OptionsMenu[i].setString(Buttons[i]);
		OptionsMenu[i].setCharacterSize(45);
		OptionsMenu[i].setOutlineThickness(3.f);
		OptionsMenu[i].setPosition(85.f, 100.f + offsetButtons * i);
	}
}

void Opcje::initText()
{
	text.setFont(this->font);
	text.setCharacterSize(30);
	text.setOutlineThickness(3.f);
	text.setFillColor(sf::Color::White);
	text.setPosition(10.f, 20.f);
	text.setString("NONE");
}

void Opcje::updateText()
{

	std::stringstream ss;

	ss << "Level: " << level << "\n";

		text.setString(ss.str());
}

void Opcje::renderText(RenderWindow& window)
{
	window.draw(text);
}

void Opcje::update(int LEVEL)
{
	level = LEVEL;
	updateText();
}

void Opcje::draw(RenderWindow& window)
{
	

	for (int i = 0; i < Max_option_menu; i++)
	{
		renderText(window);
		window.draw(OptionsMenu[i]);
	}
}
