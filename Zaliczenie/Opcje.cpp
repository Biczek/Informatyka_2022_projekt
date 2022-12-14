#include "Opcje.h"


Opcje::Opcje(float width, float height)
{
	initText();

	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here";
	}

	for (int i = 0; i < Max_option_menu; i++)
	{
		OptionsMenu[i].setFillColor(Color::White);
		OptionsMenu[i].setFont(font);
		OptionsMenu[i].setString(Buttons[i]);
		OptionsMenu[i].setCharacterSize(50);
		OptionsMenu[i].setPosition(220, 100 + offsetButtons * i);
	}
}

void Opcje::initText()
{
	text.setFont(this->font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
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
