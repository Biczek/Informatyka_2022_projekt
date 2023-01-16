#include "TEXT.h"
 TEXT::TEXT()
{
	initFont();
	initText();
}
void TEXT::initFont()
{
	if (!font.loadFromFile("Fonts/The Led Display St.ttf"))
	{
		cout << "No font is here [file function]";
	}

}

void TEXT::initText()
{
	text.setFont(font);
	text.setFillColor(Color::White);
	text.setLetterSpacing(1.f);
	text.setCharacterSize(40);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(4.f);
	text.setString("NONE");
	text.setPosition(250.f,100.f);
}

void TEXT::updateText(String string)
{
	text.setString(string);
}

void TEXT::renderText(RenderTarget& target)
{
	target.draw(text);
}
