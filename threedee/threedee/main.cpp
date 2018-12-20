#include<SFML/Graphics.hpp>
#include<iostream>
#include "Points.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	window.setVerticalSyncEnabled(true);
	Points point(500);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		point.Update(window, true);


		window.clear();
		window.draw(point);
		window.display();
	}

	return 0;
}