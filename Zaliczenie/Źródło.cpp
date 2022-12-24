/* Gra wedle scenariusza 1 */

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>

#include "Enemies.h"
#include "Player.h"
#include "mainMenu.h"
#include "Confirm.h"

using namespace sf;


float velocity = 2.f;


class helpWindow
{
private:

	Text text;
	Font font;
	
public:

	helpWindow();

	void initText();
	void initFont();

	void renderWindow(RenderTarget& target);
	void renderText(RenderTarget& target);

	void updateWindow(RenderTarget& target);
	void updateText(RenderTarget& target);

	

};
helpWindow::helpWindow()
{
	initFont();
	initText();
	
};

void helpWindow::initFont()
{
	font.loadFromFile("Fonts/Dosis-Light.ttf");
}
void helpWindow::initText()
{
	
	

	text.setFont(font);
	text.setCharacterSize(24);
	text.setOrigin(150,200);
	text.setPosition(500.f, 400.f);
	text.setString("NONE");

}


void helpWindow::renderWindow(RenderTarget& target)
{
	renderText(target);

}
void helpWindow::updateWindow(RenderTarget& target)
{
	updateText(target);
}


void helpWindow::renderText(RenderTarget &target)
{
	target.draw(text);
}
void helpWindow::updateText(RenderTarget& target)
{
	std::stringstream ss;

	ss << "\t ---- Jak Grac: ----" << "\n"
		<< "\tA - ruch w lewo " << "\n"
		<< "\tD - ruch w prawo" << "\n"
		<< "\tW - ruch w gore" << "\n"
		<< "\tS - ruch w dol" << "\n"
		<< "\tlewy przycisk myszy - strzal" << "\n"
		<< "\n"
		<< "Jesli chcesz opuscic okno POMOC - kliknij 1" << "\n";


		text.setString(ss.str());
}





int main()
{
	srand(static_cast<unsigned>(time(0)));


	Enemies Enemies;
	Player player;
	helpWindow help;
	
	//Make a Mainwindow

	RenderWindow MENU(VideoMode(1000.f, 800.f), "Main Menu", Style::Close || Style::Titlebar);
	mainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
	
	//setBackground
	RectangleShape background;
	background.setSize(Vector2f(1000.f, 800.f));
	Texture Maintexture;
	Maintexture.loadFromFile("Images/Galaktyka.jpg");
	background.setTexture(&Maintexture);

	//photo to the game
	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(1000.f, 800.f));
	Texture back_texture;
	back_texture.loadFromFile("Images/Ziemia.jpg");
	Pbackground.setTexture(&back_texture);

	//photo to options
	RectangleShape Obackground;
	Pbackground.setSize(Vector2f(400.f, 800.f));
	Texture Optiontexture;
	back_texture.loadFromFile("Images/Konstelacja.jpg");
	Pbackground.setTexture(&Optiontexture);

	//About 
	RectangleShape ABbackground;
	ABbackground.setSize(Vector2f(800.f, 800.f));
	Texture Abouttexture;
	Abouttexture.loadFromFile("Images/Konstelacja.jpg");
	ABbackground.setTexture(&Abouttexture);


	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}
			if(event.type == Event::KeyReleased)
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Play(VideoMode(1000, 800), "game_name");
					RenderWindow OPTIONS(VideoMode(400, 800), "OPTIONS");
					RenderWindow ABOUT(VideoMode(800, 800), "ABOUT");
					
					int x = mainMenu.MainMenuPressed();

					if (x == 0)
					{
						bool close = false;

							while (Play.isOpen())
							{
								Event aevent;
								

								while (Play.pollEvent(aevent))
								{
								

									if (aevent.type == Event::Closed)
									{
										Play.close();
									}
									if (aevent.type == Event::KeyPressed)
									{
										

										if (aevent.key.code == Keyboard::Escape)
										{
											RenderWindow CONFIRM(VideoMode(600, 200), "CONFIRM", Style::Close || Style::Titlebar);
											Confirm confirmMenu(CONFIRM.getSize().x, CONFIRM.getSize().y);

										

											while (CONFIRM.isOpen())
											{

												Event bevent;

												while (CONFIRM.pollEvent(bevent))
												{
													if (bevent.type == Event::Closed)
													{
														CONFIRM.close();
													}
													if (bevent.type == Event::KeyPressed)
													{

														if (bevent.key.code == Keyboard::Up)
														{
															confirmMenu.MoveUp();
														}

														if (bevent.key.code == Keyboard::Down)
														{
															confirmMenu.MoveDown();
														}
													
														if (bevent.key.code == Keyboard::Return)
														{
															if (confirmMenu.ReturnMenuSelected() == true)
															{
																CONFIRM.close();
																close = true;
															}
															else
															{
																CONFIRM.close();
															}
															
														}
													
													

													}
												}
												CONFIRM.clear();
												confirmMenu.draw(CONFIRM);
												CONFIRM.display();
												

											}
											if (close == true)
											{
												Play.close();
											}
											
										}

									}

								}
								
								OPTIONS.close();
								ABOUT.close();
								Play.clear();
								//Play.draw(Pbackground);
								//Update
								Enemies.updateEnemies(Play);
								player.updatePlayer(Play, velocity);
								//Draw
								Enemies.renderEnemies(Play);
								player.renderPlayer(Play);

								Play.display();
							

							}
					}

					if (x == 1)
					{
						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
							}
							
							Play.close();
							OPTIONS.clear();
							ABOUT.close();
							//OPTIONS.draw(Obackground);

							OPTIONS.display();

						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							Event aevent;
							while (ABOUT.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									ABOUT.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										ABOUT.close();
									}
								}
							}
							
							Play.close();
							OPTIONS.close();
							ABOUT.clear();
							//ABOUT.draw(ABbackground);

							ABOUT.display();

						}
					}
					if (x == 3)
					{
						MENU.close();
						break;
					}
				}
		}
		MENU.clear();
		//MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
	
}

