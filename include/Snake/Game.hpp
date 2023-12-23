#pragma once
#include "SFML/Graphics.hpp"
#include "Snake.hpp"
#include "PlayerInput.hpp"
#include "Statistic.hpp"
#include "Sidebar.hpp"
#include "Timer.hpp"
#include "Apple.hpp"
#include <random>

class Game
{
public:
	Game();
	void run();

private:
	void processInput();
	void update(sf::Time delta);
	void render();

private:
	static sf::Vector2f WINDOW_SIZE;
	sf::RenderWindow window;
	sf::Font font;
	Timer timer;
	Statistic statistic;
	Sidebar sideBar;
	PlayerInput playerInput;
	Snake snake;
	Apple apple;
	bool isPaused;
	bool isGameOver;
	std::random_device rand;

private:
	void gameOver();
	bool isGameOverConditionsFullfilled();
	void switchPause();
	void restart();
	void moveAppleToRandimPosition();
};
