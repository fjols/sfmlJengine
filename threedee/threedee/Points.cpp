#include "Points.h"



Points::Points(int amountOfPoints)
{
	m_point.setPrimitiveType(sf::Points); //!< Set the primitive type to be points.
	m_point.resize(amountOfPoints); //!< Size of the vertex array
	for (int i = 0; i < m_point.getVertexCount(); i++) {
		m_point[i].position = Generate(); //!< Generate a random position for each point.
	}
}

void Points::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_point); //!< Draw the points
}

sf::Vector2f Points::Generate()
{
	float randomX = rand() % 600; //!< Random number between 1 and 600.
	float randomY = rand() % -800; //!< Random number between 1 and -800.
	for (int i = 0; i < m_point.getVertexCount(); i++) {
		return sf::Vector2f(randomX, randomY); //!< Return a vector with the two random numbers.
	}
}

void Points::Update(sf::RenderTarget &target, bool FadeColoursOn)
{
	float dt = timer.restart().asSeconds(); //!< Deltatime.
	for (int i = 0; i < m_point.getVertexCount(); i++) {
		m_point[i].position.y += m_kGravity.y  * dt; //!< Makes the points move down the screen.
		
		if(FadeColoursOn) //!< If true, run the FadeColours method. If false keep it white.
			FadeColours(); //!< Make the colours change.


		if (m_bToggle == false) {
			m_point[i].position.x += m_kGravity.x * dt; //!< Move the points to the right.
			m_bToggle = true;
		}
		else if (m_bToggle == true) {
			m_point[i].position.x += -m_kGravity.x * dt; //!< Move the points to the left.
			m_bToggle = false;
		}

		if (m_point[i].position.y >= target.getSize().y) //!< If the points hit the bottom of the screen.
		{
			m_point[i].position.y -= 600; //!< Move the points to the top of the screen.
		}
		if (m_point[i].position.x <= 0) { //!< If the points hit the left of the screen.
			m_point[i].position.x += 600; //!< Move the points to the right of the screen.
		}
		if (m_point[i].position.x >= target.getSize().x) { //!< If the points hit the right of the screen.
			m_point[i].position.x -= 600; //!< Move the points to the left of the screen.
		}



	}
}

void Points::FadeColours()
{
	for (int i = 0; i < m_point.getVertexCount(); i++) {
		m_point[i].color.r = rand() % 255; //!< Random number between 1 and 255 for the red.
		m_point[i].color.g = rand() % 255; //!< Random number between 1 and 255 for the green.
		m_point[i].color.b = rand() % 255; //!< Random number between 1 and 255 for the blue.
	}
}

void Points::DoCircle(sf::Vector2f position, float radius)
{
	for (int i = 0; i < m_point.getVertexCount(); i++) {
		m_fTheta += m_fThetaStep; //!< Add theta to theta step.
		m_point[i].position = sf::Vector2f(position.x + cos(m_fTheta) * radius, position.y + sin(m_fTheta) * radius); //!< Make the circle.
	}
}



