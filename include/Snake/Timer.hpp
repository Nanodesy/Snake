#pragma once
#include "SFML/System.hpp"

class Timer
{
public:
	Timer();
	sf::Time getElapsedTime();
	sf::Time restart();
	void start();
	void stop();

private:
	sf::Clock clock;
	sf::Time elapsedTime;
	bool isStopped;
};
