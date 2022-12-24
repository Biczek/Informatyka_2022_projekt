#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define Max_confirm_menu 3

class Confirm
{
private:
	int ConfirmMenuSelected;
	Font font;
	Text ConfirmMenu[Max_confirm_menu];

public:
	Confirm(float width, float height);
	~Confirm();

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	bool ReturnMenuSelected();
	int ConfirmMenuPressed()
	{
		return ConfirmMenuSelected;
	}
};

