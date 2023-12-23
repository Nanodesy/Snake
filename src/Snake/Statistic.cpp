#include "Statistic.hpp"
#include <iostream>
#include <cmath>

Statistic::Statistic() : appleCount(0), snakeSize(3)
{
}

void Statistic::setAppleCount(int appleCount)
{
	this->appleCount = appleCount;
}

int Statistic::getAppleCount()
{
	return this->appleCount;
}

int Statistic::getApplesPerMinute()
{
	if (appleCount == 0)
		return 0;
	float minutesFromGameStart = gameTimer.getElapsedTime().asSeconds() / 60;
	return std::ceil(appleCount / minutesFromGameStart);
}

void Statistic::setSnakeSize(int snakeSize)
{
	this->snakeSize = snakeSize;
}

int Statistic::getSnakeSize()
{
	return this->snakeSize;
}

uint Statistic::getGameDurationMilliseconds()
{
	return this->gameTimer.getElapsedTime().asMilliseconds();
}

void Statistic::stopTimer()
{
	gameTimer.stop();
}

void Statistic::startTimer()
{
	gameTimer.start();
}

void Statistic::reset()
{
	gameTimer.restart();
	appleCount = 0;
	snakeSize = 3;
}
