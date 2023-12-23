#include <deque>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class Snake
{
public:
	Snake(std::deque<sf::Vector2f> snakeParts);
	sf::Vector2f getHeadPosition();
	bool isCollideSelf();
	int getLength();
	bool hasPartAt(sf::Vector2f position);
	void growSnake();
	bool move(sf::Time delta, sf::Vector2f direction);
	void render(sf::RenderWindow *window);

private:
	std::deque<sf::Vector2f> snakeParts;
	sf::Vector2f currentDirection;
	sf::Vector2f nextStepDirection;
	sf::Time timeFromLastStep;
	int snakeGrowCounter;

private:
	void setNextStepDirection(sf::Vector2f direction);
	bool isOutOfBounds(sf::Vector2f snakeHeadPosition);
};
