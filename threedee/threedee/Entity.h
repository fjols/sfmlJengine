#pragma once
#include<SFML/Graphics.hpp>
class Entity : public sf::Drawable
{
public:
	Entity(sf::Vector2f pos, sf::Vector2f size);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::RectangleShape GetShape();
private:
	sf::RectangleShape shape;
};

