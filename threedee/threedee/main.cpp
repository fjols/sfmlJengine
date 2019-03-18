#include<SFML/Graphics.hpp>
#include<iostream>
#include "Points.h"
#include "Entity.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

	float fFrameTime = 1.f / 60.f; // Frame time.
	sf::Clock clock;


	window.setVerticalSyncEnabled(true);
	Points point(1000);
	Points pointOne(1000);
	Points pointTwo(1000);
	Entity platform(sf::Vector2f(0, 400), sf::Vector2f(600, 50));
	Player player(sf::Vector2f(0, 200), sf::Vector2f(50, 50));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float m_fElapsedTime = clock.getElapsedTime().asSeconds(); // Get the elapsed time in seconds.
		if (m_fElapsedTime > fFrameTime)
		{
			//point.Update(window, true);
			//player.Update();
			//player.Collision(platform.GetShape());
			//point.SineWave(sf::Vector2f(0, 100), 2.f, 2.f);
			//pointOne.SineWave(sf::Vector2f(0, 100), 2.f, 4.f);
			pointTwo.SineWave(sf::Vector2f(0, 100), 4.f, 2.f);
			clock.restart();
		}


		window.clear();
		//window.draw(player);
		//window.draw(platform);
		//window.draw(point);
		//window.draw(pointOne);
		window.draw(pointTwo);
		window.display();
	}

	return 0;
}