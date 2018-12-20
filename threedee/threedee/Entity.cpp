#include "Entity.h"



Entity::Entity(sf::Vector2f pos, sf::Vector2f size)
{
	shape.setPosition(pos);
	shape.setSize(size);
	shape.setFillColor(sf::Color::Yellow);
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape);
}

sf::RectangleShape Entity::GetShape()
{
	return shape;
}
