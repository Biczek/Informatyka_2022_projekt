/* Gra wedle scenariusza 1*/

#include "Gra.h"
#include "Help_F1.h"
#include <iostream>

using namespace sf;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	Gra game;
	Help_F1 help;

		while (help.running())
		{
			help.update();
			help.render();
		}
		
	return 0;
}