#pragma once
#include "game.h"


class TEXT
{
private:
	Text text;
	Font font;


public:
	TEXT();
	void initFont();
	void initText();
	void updateText(String string);
	void renderText(RenderTarget& target);

};

