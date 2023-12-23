#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class Apple
{
public:
	Apple();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void render(sf::RenderWindow *window);

private:
	sf::Vector2f position;
};
