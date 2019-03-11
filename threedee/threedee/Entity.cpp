#include "Entity.h"



Entity::Entity(sf::Vector2f pos, sf::Vector2f size)
{
	shape.setPosition(pos); // Set the position of the shape.
	shape.setSize(size); // Set the size of the shape.
	shape.setFillColor(sf::Color::Yellow); // Set the colour of the shape.
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape); // Draw the entity shape.
}

sf::RectangleShape Entity::GetShape()
{
	return shape; // Return the entity shape.
}
