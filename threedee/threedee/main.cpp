#include<SFML/Graphics.hpp>
#include<iostream>
#include "Points.h"
#include "Entity.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	window.setVerticalSyncEnabled(true);
	Points point(500);
	//Entity platform(sf::Vector2f(0, 400), sf::Vector2f(600, 50));
	//Player player(sf::Vector2f(0, 200), sf::Vector2f(50, 50));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		point.Update(window, true);
		//player.Update();
		//player.Collision(platform.GetShape());

		window.clear();
		//window.draw(player);
		//window.draw(platform);
		window.draw(point);
		window.display();
	}

	return 0;
}