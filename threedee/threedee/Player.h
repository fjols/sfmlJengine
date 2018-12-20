#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Player : public sf::Drawable
{
public:
	Player(sf::Vector2f pos, sf::Vector2f size);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void Update();
	void Collision(sf::RectangleShape other);
private:
	sf::RectangleShape player;
	const float m_fGravity = 10.f;
	float m_fSpeed = 10.f;
	sf::Clock timer;

	int top;
	int bottom;
	int left;
	int right;


};

