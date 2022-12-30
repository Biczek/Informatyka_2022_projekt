#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>
#include<iostream>
#include<vector>


using namespace sf;
using namespace std;


class Player
{
private:

	bool shot;
	Text text;
	Font font;

public:

	RectangleShape Gracz;

	Player();

	void initVariables();

	void initPlayer();
	void updatePlayer(RenderTarget& target, float velocity);
	void renderPlayer(RenderTarget& target);


	const sf::RectangleShape& getShape() const;

};



