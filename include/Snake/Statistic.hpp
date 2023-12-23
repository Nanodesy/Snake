#pragma once
#include "SFML/System.hpp"
#include "Timer.hpp"

class Statistic
{
	public:
		Statistic();
		void setAppleCount(int appleCount);
		int getAppleCount();
		int getApplesPerMinute();
		void setSnakeSize(int size);
		int getSnakeSize();
		uint getGameDurationMilliseconds();
		void stopTimer();
		void startTimer();
		void reset();

	private:
		Timer gameTimer;
		int appleCount;
		int snakeSize;
};
