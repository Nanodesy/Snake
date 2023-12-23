#include "Snake.hpp"
#include <iostream>

Snake::Snake(std::deque<sf::Vector2f> snakeParts) : snakeParts(snakeParts),
													currentDirection(0, -1),
													nextStepDirection(0, -1),
													snakeGrowCounter(0)
{
}

sf::Vector2f Snake::getHeadPosition()
{
	return snakeParts.front();
}

bool Snake::isCollideSelf()
{
	for (u_long i = 0; i < snakeParts.size(); i++)
		for (u_long j = i + 1; j < snakeParts.size(); j++)
			if (snakeParts[i] == snakeParts[j])
				return true;
	return false;
}

int Snake::getLength()
{
	return snakeParts.size();
}

bool Snake::hasPartAt(sf::Vector2f position)
{
	for (u_long i = 0; i < snakeParts.size(); i++)
		if (snakeParts[i] == position)
			return true;
	return false;
}

void Snake::growSnake()
{
	snakeGrowCounter++;
}

/**
 * @brief Execute move logic of Snake
 * 
 * @param delta - time delta between move execution
 * @param direction - snake's move direction
 * 
 * @return return true if execution of logic succeded, otherwise false (i.e. out of bounds).
 */
bool Snake::move(sf::Time delta, sf::Vector2f direction)
{
	timeFromLastStep += delta;
	setNextStepDirection(direction);
	if (timeFromLastStep.asMilliseconds() >= 200)
	{
		currentDirection = nextStepDirection;
		sf::Vector2f newSnakeHeadPosition = snakeParts.front();
		newSnakeHeadPosition.x += currentDirection.x * 40;
		newSnakeHeadPosition.y += currentDirection.y * 40;

		if (isOutOfBounds(newSnakeHeadPosition)) {
			return false;
		}

		if (snakeGrowCounter > 0)
			snakeGrowCounter--;
		else
			snakeParts.pop_back();
		snakeParts.push_front(newSnakeHeadPosition);

		timeFromLastStep = sf::Time::Zero;
	}
	return true;
}

void Snake::render(sf::RenderWindow *window)
{
	sf::Vector2f snakePartSize(sf::Vector2f(39, 39));

	sf::RectangleShape bodyPart(snakePartSize);
	bodyPart.setFillColor(sf::Color(0xD5, 0xE8, 0xD4));
	bodyPart.setOutlineColor(sf::Color::Black);
	bodyPart.setOutlineThickness(1);
	for (u_long i = 1; i < snakeParts.size(); i++)
	{
		bodyPart.setPosition(snakeParts[i].x, snakeParts[i].y);
		window->draw(bodyPart);
	}

	sf::RectangleShape headPart(snakePartSize);
	headPart.setPosition(snakeParts.front().x, snakeParts.front().y);
	headPart.setFillColor(sf::Color(0x37, 0xCC, 0x31));
	headPart.setOutlineColor(sf::Color::Black);
	headPart.setOutlineThickness(1);
	window->draw(headPart);
}

void Snake::setNextStepDirection(sf::Vector2f direction)
{
	if (direction.x == 0 && direction.y == 0)
		return;
	if (direction.x != 0 && direction.y != 0)
		return;
	if (nextStepDirection == direction)
		return;
	if (direction.x == 0 && std::abs(currentDirection.y) == std::abs(direction.y))
		return;
	if (direction.y == 0 && std::abs(currentDirection.x) == std::abs(direction.x))
		return;
	nextStepDirection = direction;
}

bool Snake::isOutOfBounds(sf::Vector2f snakeHeadPosition)
{
	if (snakeHeadPosition.x < 0 || snakeHeadPosition.x >= 600)
		return true;
	if (snakeHeadPosition.y < 0 || snakeHeadPosition.y >= 600)
		return true;
	return false;
}
