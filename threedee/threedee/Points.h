#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<random>

class Points : public sf::Drawable
{
public:
	Points(int amountOfPoints); //!< \fn Constructor.
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< \fn Drawing function.
	sf::Vector2f Generate(); //!< \fn Generate the positions of the points.
	void Update(sf::RenderTarget &target, bool FadeColoursOn); //!< \fn Update the positions of the points.
	void FadeColours(); //!< \fn Change the colours.
	void DoCircle(sf::Vector2f position, float radius);
private:
	const sf::Vector2f m_kGravity = sf::Vector2f(1.f, 40.f); //!< Gravity vector.
	sf::VertexArray m_point; //!< Vertex array of points.
	sf::Clock timer; //A timer to manage time.
	bool m_bToggle = false; //Toggle variable 
	float m_fTheta = 0;
	float m_fThetaStep = 360 / 60;
	//float m_fRadius = 200.5f;


};

