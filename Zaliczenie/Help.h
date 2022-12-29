#pragma once
#include"SFML\Graphics.hpp"
#include"iostream"


#define Max_help_menu 5

using namespace std;
using namespace sf;

class Help
{
private:
	Font font;
	Text HelpMenu[Max_help_menu];


public:

	Help(float width, float height);
	~Help();

	void draw(RenderWindow& window);
};

