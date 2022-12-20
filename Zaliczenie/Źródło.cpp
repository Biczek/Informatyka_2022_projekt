/* Gra wedle scenariusza 1 */

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<ctime>

using namespace sf;

void Update( RectangleShape &square, RenderWindow &window, CircleShape& bullet);
void Draw(RenderWindow &window, RectangleShape &square, CircleShape &bullet, ConvexShape &convex);
void Draw_bullet(RectangleShape& square, CircleShape& bullet, RenderWindow &window);
void Draw_enemies(ConvexShape &convex, RenderWindow &window);

float velocity = 5.f;
bool is_shot = false;
int max_enemies = 10;
int enemies = 0;




int main()
{
	srand(static_cast<unsigned>(time(0)));
	

	//Okno
	RenderWindow window(VideoMode(1000, 800), "Game");
	window.setFramerateLimit(60);

	//Postaæ tymczasowa
	RectangleShape square(Vector2f(100.f, 100.f));
	square.setFillColor(Color::Red);
	square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	square.setOrigin(50.f, 50.f);

	//Pocisk
	CircleShape bullet;
	bullet.setRadius(10.f);
	bullet.setFillColor(Color::Blue);
	bullet.setOutlineThickness(5.f);
	bullet.setOutlineColor(Color::Cyan);
	bullet.setOrigin(bullet.getRadius(), bullet.getRadius());
	bullet.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	//Wróg
	ConvexShape convex;
	convex.setPointCount(6);

	convex.setPoint(0, Vector2f(10.f,0.f));
	convex.setPoint(1, Vector2f(20.f, 15.f));
	convex.setPoint(2, Vector2f(15.f, 40.f));
	convex.setPoint(3, Vector2f(10.f, 20.f));
	convex.setPoint(4, Vector2f(5.f, 40.f));
	convex.setPoint(5, Vector2f(0.f, 15.f));
	convex.setFillColor(Color::Yellow);
	convex.setOrigin(15.f,20.f);
	convex.rotate(180);
	convex.setPosition(50.f, 50.f);
	convex.setScale(Vector2f(2.f, 2.f));



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

		}


		//Update

		Update( square, window, bullet);

		//Draw
		Draw(window, square, bullet, convex);
		Draw_enemies(convex, window);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Draw_bullet(square, bullet, window);
			is_shot = true;
		}
	}

	return 0;
}

void Update( RectangleShape &square, RenderWindow &window, CircleShape& bullet)
{
	

	if (Keyboard::isKeyPressed(Keyboard::A) && square.getPosition().x > 0 + square.getSize().x / 2)
	{
		square.move(Vector2f(-velocity,0.f));
		
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && square.getPosition().x + square.getSize().x / 2 < window.getSize().x)
	{
		square.move(Vector2f(velocity, 0.f));
		
	}
	if (Keyboard::isKeyPressed(Keyboard::W) && square.getPosition().y > 0 + square.getSize().y / 2)
	{
		square.move(Vector2f(0.f, -velocity));

	}
	if (Keyboard::isKeyPressed(Keyboard::S) && square.getPosition().y + square.getSize().y / 2 < window.getSize().y)
	{
		square.move(Vector2f(0.f, velocity));
		
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		square.setFillColor(Color::Blue);

	}
	else
	{
		square.setFillColor(Color::Red);
	}

	if (is_shot == true)
	{
		bullet.move(0.f, -5.f);
		if (bullet.getPosition().y == 0)
		{
			is_shot = false;
		}
	}
	
}
void Draw(RenderWindow &window, RectangleShape &square, CircleShape &bullet, ConvexShape &convex)
{
	window.clear(Color::Black);

	//Draw stuff

	window.draw(square);
	window.draw(convex);

	if (is_shot == true)
	{
		window.draw(bullet);
	}
	if(enemies < max_enemies)
	{
		Draw_enemies(convex, window);
	}
	window.display();
}

void Draw_bullet(RectangleShape& square, CircleShape& bullet, RenderWindow &window)
{
	window.draw(bullet);
	bullet.setPosition(square.getPosition().x, square.getPosition().y);
	window.display();
}
void Draw_enemies(ConvexShape& convex, RenderWindow& window)
{
	window.draw(convex);
	convex.setPosition(Vector2f(rand() % 1000, rand() % 200));

}