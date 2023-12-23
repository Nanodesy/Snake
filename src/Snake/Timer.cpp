#include "Timer.hpp"

Timer::Timer()
{
}

sf::Time Timer::getElapsedTime()
{
	if (isStopped)
		return elapsedTime;
	return clock.getElapsedTime() + elapsedTime;
}

sf::Time Timer::restart()
{
	isStopped = false;
	sf::Time totalElapsedTime = clock.restart() + elapsedTime;
	elapsedTime = sf::Time::Zero;
	return totalElapsedTime;
}

void Timer::start()
{
	if (isStopped)
	{
		isStopped = false;
		clock.restart();
	}
}

void Timer::stop()
{
	if (!isStopped)
	{
		isStopped = true;
		elapsedTime += clock.restart();
	}
}
