#include "TEXT.h"
 TEXT::TEXT()
{
	initFont();
	initText();
}
void TEXT::initFont()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		cout << "No font is here [file function]";
	}

}

void TEXT::initText()
{
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setCharacterSize(40);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2.f);
	text.setString("NONE");
	text.setPosition(300.f,100.f);
}

void TEXT::updateText(String string)
{
	text.setString(string);
}

void TEXT::renderText(RenderTarget& target)
{
	target.draw(text);
}
