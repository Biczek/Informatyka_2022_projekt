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
#include "Opcje.h"
#include "TEXT.h"

using namespace sf;


float velocity = 1.f;
int level = 1;

int main()
{
	srand(static_cast<unsigned>(time(0)));

	bool GamePlay = false;
	bool GAMEOVER = false;
	
	
	
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
	Pbackground.setSize(Vector2f(1000.f,1000.f));
	Texture back_texture;
	if (!back_texture.loadFromFile("Images/Niebo.jpg"))
	{
		cout << "ERROR::LOAD_TEXTURE::GAME BACKGROUND" << "\n";
	}
	Pbackground.setTexture(&back_texture);

	//photo to options
	RectangleShape Obackground;
	Obackground.setSize(Vector2f(800.f, 800.f));
	Texture Optiontexture;
	Optiontexture.loadFromFile("Images/Konstelacja.jpg");
	Obackground.setTexture(&Optiontexture);

	//About 
	RectangleShape ABbackground;
	ABbackground.setSize(Vector2f(800.f, 800.f));
	Texture Abouttexture;
	Abouttexture.loadFromFile("Images/Konstelacja.jpg");
	ABbackground.setTexture(&Abouttexture);

	//Help
	RectangleShape Helpbackground;
	Helpbackground.setSize(Vector2f(600.f,600.f));
	Texture Helptexture;
	Helptexture.loadFromFile("Images/Galaktyka.jpg");
	Helpbackground.setTexture(&Helptexture);
	

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			

			if (event.type == Event::Closed)
			{
				MENU.close();
			}
			if (event.type == Event::KeyReleased)

				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();

					GAMEOVER = false;
					GamePlay = false;
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();

					GAMEOVER = false;
					GamePlay = false;
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Play(VideoMode(1000, 800), "game_name");
					RenderWindow OPTIONS(VideoMode(800, 800), "OPTIONS");
					RenderWindow ABOUT(VideoMode(800, 800), "ABOUT");
					
					Game game(Play);

					int x = mainMenu.MainMenuPressed();

					if (x == 0)
					{
						
						game.setLevel(level);

							while (Play.isOpen())
							{
								Event aevent;
								

								while (Play.pollEvent(aevent))
								{
									if (!game.endGame())
									{
										GAMEOVER = true;
									}

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
												HELP.draw(Helpbackground);
												help.draw(HELP);
												HELP.display();
											}
										}

										if (aevent.key.code == Keyboard::S)
										{
											ofstream zapis("dane.txt", ios::app);
											zapis << "punkty : " << game.points_return() << "\n";
											zapis.close();
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

														if (aevent.key.code == Keyboard::Left)
														{
															confirmMenu.MoveUp();
														}

														if (aevent.key.code == Keyboard::Right)
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

												

												ofstream zapis("dane.txt", ios::app);
												zapis << "punkty : " << game.points_return() << "\n";
												zapis.close(); 

												

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
									Play.draw(Pbackground);
									//Update

									if (!GAMEOVER)
									{
										game.update(Play, velocity);
									}
									else
									{
										game.renderGameOver(Play);
									}
								

									//Draw
									
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
							Opcje opcje(OPTIONS.getSize().x, OPTIONS.getSize().y);
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Num1)
									{
										level = 1;
										
									}
									if (aevent.key.code == Keyboard::Num2)
									{
										level = 2;
										
									}
									if (aevent.key.code == Keyboard::Num3)
									{
										level = 3;
										
									}
									if (aevent.key.code == Keyboard::Num4)
									{
										level = 4;
										
									}
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
							opcje.update(level);

							opcje.draw(OPTIONS);
							

							OPTIONS.display();

						}
					}
					if (x == 2)
					{
						bool once = true;
						TEXT text;
						stringstream ss;

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

								

								fstream zapis("dane.txt");
								string lista[10];
								string linia;

								do
								{
									for (int i = 0; i < 10; i++)
									{
										getline(zapis, linia);
										lista[i] = linia;
									}
									 
									
									
								} while (linia != ""); 
								zapis.close(); 
								if (once == true)
								{
									ss  <<"Hiscore : " <<"\n"
									    << lista[0] << "\n"
										<< lista[1] << "\n"
										<< lista[2] << "\n"
										<< lista[3] << "\n"
										<< lista[4] << "\n"
										<< lista[5] << "\n"
										<< lista[6] << "\n"
										<< lista[7] << "\n"
										<< lista[8] << "\n"
										<< lista[9] << "\n";

									once = false;
								}

							}
							
							Play.close();
							OPTIONS.close();
							ABOUT.clear();
							ABOUT.draw(ABbackground);

							text.updateText(ss.str());
							text.renderText(ABOUT);
							
							

							ABOUT.display();

						}
					}
					if (x == 3)
					{
						MENU.close();
						break;
					}
					break;
				}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}
	
}

