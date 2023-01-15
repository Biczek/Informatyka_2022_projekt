#pragma once
#include"SFML\Graphics.hpp"
#include"iostream"


#define Max_help_menu 7

using namespace std;
using namespace sf;

class Help
{
private:

	Font font;
	Text HelpMenu[Max_help_menu];
	float Offset = 50.f;

	const char* Buttons[Max_help_menu] = { "	Simple instruction" , " Left arrow - move left" ,"Right arrow - move right" 
	, "	Up arrow - move up" ,"Down arrow - move down" ,"		 Space - shoot", "			Esc - exit"};

public:

	Help(float width, float height);	
	~Help();

	void draw(RenderWindow& window);
};

