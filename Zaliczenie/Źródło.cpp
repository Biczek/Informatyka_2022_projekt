/* Gra wedle scenariusza 1 */

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>
#include<sstream>

#include "Game.h"
#include "mainMenu.h"
#include "Confirm.h"
#include "Help.h"

using namespace sf;


float velocity = 1.f;

int main()
{
	srand(static_cast<unsigned>(time(0)));

	bool GamePlay = false;

	Game game;
	
	
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
	back_texture.loadFromFile("Images/Galaktyka.jpg");
	Pbackground.setTexture(&back_texture);

	//photo to options
	RectangleShape Obackground;
	Pbackground.setSize(Vector2f(800.f, 800.f));
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
					RenderWindow OPTIONS(VideoMode(800, 800), "OPTIONS");
					RenderWindow ABOUT(VideoMode(800, 800), "ABOUT");
					
					int x = mainMenu.MainMenuPressed();

					if (x == 0)
					{
						

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

										if (aevent.key.code == Keyboard::F1)
										{
											RenderWindow HELP(VideoMode(600, 600), "Help", Style::Titlebar);
											Help help(HELP.getSize().x, HELP.getSize().y);

											while (HELP.isOpen())
											{
												while (HELP.pollEvent(aevent))
												{
													if (aevent.type == Event::KeyPressed)
													{
														if (aevent.key.code == Keyboard::Escape)
														{
															HELP.close();
														}
													}
												}
												HELP.clear();
												help.draw(HELP);
												HELP.display();
											}
										}
										
										if (aevent.key.code == Keyboard::Escape)
										{
											RenderWindow CONFIRM(VideoMode(600, 200), "CONFIRM");
											Confirm confirmMenu(CONFIRM.getSize().x, CONFIRM.getSize().y);


											while (CONFIRM.isOpen())
											{

												

												while (CONFIRM.pollEvent(aevent))
												{
													if (aevent.type == Event::KeyPressed)
													{

														if (aevent.key.code == Keyboard::Up)
														{
															confirmMenu.MoveUp();
														}

														if (aevent.key.code == Keyboard::Down)
														{
															confirmMenu.MoveDown();
														}
													
														if (aevent.key.code == Keyboard::Return)
														{
															
															CONFIRM.close();
															
														}
													
													

													}
												}
												CONFIRM.clear();
												confirmMenu.draw(CONFIRM);
												CONFIRM.display();
												

											}

											if (confirmMenu.ReturnMenuSelected() == true)
											{
												GamePlay = true;
											}
											else
											{
												GamePlay = false;
											}
											
										
										}
										


									}

								}
								if (GamePlay == false)
								{
									OPTIONS.close();
									ABOUT.close();
									Play.clear();
									//Update
									game.update(Play,velocity);

									//Draw
									//Play.draw(Pbackground);
									game.render(Play);
									

									Play.display();
								}
								else
								{
									Play.close();
								}
							

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
							OPTIONS.draw(Obackground);

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
							ABOUT.draw(ABbackground);

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
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
	
}

