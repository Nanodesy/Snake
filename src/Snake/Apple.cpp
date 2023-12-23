#include "Apple.hpp"

Apple::Apple()
{
}

void Apple::setPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f Apple::getPosition()
{
	return this->position;
}

void Apple::render(sf::RenderWindow *window)
{
	sf::CircleShape circle(20);
	circle.setFillColor(sf::Color(0xF8, 0xCE, 0xCC));
	circle.setPosition(position);
	window->draw(circle);
}
