#include "Player.h"



Player::Player(sf::Vector2f pos, sf::Vector2f size)
{
	player.setSize(size);
	player.setPosition(pos);
	player.setFillColor(sf::Color::Cyan);

	top = player.getPosition().y;
	left = player.getPosition().x;
	right = player.getPosition().x + (player.getLocalBounds().width);
	bottom = player.getPosition().y + (player.getLocalBounds().height);


}


void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(player);
}

void Player::Update()
{
	float dt = timer.restart().asSeconds();

	player.move(0, m_fGravity);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.move(0, -m_fSpeed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.move(0, m_fSpeed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.move(-m_fSpeed * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.move(m_fSpeed * dt, 0);
	}

	
}

void Player::Collision(sf::RectangleShape other) {
	if (bottom > other.getPosition().y)
	{
		sf::Vector2f difference = sf::Vector2f(0, player.getSize().y);
		player.move(difference);
		std::cout << "COLLIDING" << std::endl;
	}

}
