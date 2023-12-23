#include "Game.hpp"
#include <iostream>

sf::Vector2f Game::WINDOW_SIZE = sf::Vector2f(800, 600);

Game::Game() : window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Snake"),
			   sideBar(&statistic),
			   snake(std::deque<sf::Vector2f>{sf::Vector2f(280, 280), sf::Vector2f(280, 320), sf::Vector2f(280, 360)})
{
	font.loadFromFile("/Users/vaazarov/Documents/Projects/C:C++/snake/Times New Roman.ttf");
	window.setFramerateLimit(30);
	playerInput.onPausePressed([this](){switchPause();});
	playerInput.onRestartPressed([this](){restart();});
	playerInput.onExitPressed([this](){window.close();});
	moveAppleToRandimPosition();
}

void Game::run()
{
	timer.restart();
	while (window.isOpen())
	{
		sf::Time delta = timer.restart();
		processInput();
		if (!isPaused && !isGameOver) update(delta);
		render();
	}
}

void Game::processInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
			playerInput.handleInputEvent(&event);
	}
}

void Game::update(sf::Time delta)
{
	bool isSnakeMoveSuccefull = snake.move(delta, playerInput.getPlayerMovementDirection());
	sf::Vector2f snakeHeadPosition = snake.getHeadPosition();
	if (snakeHeadPosition == apple.getPosition())
	{
		snake.growSnake();
		statistic.setSnakeSize(statistic.getSnakeSize() + 1);
		statistic.setAppleCount(statistic.getAppleCount() + 1);
		moveAppleToRandimPosition();
	}
	if (!isSnakeMoveSuccefull)
		gameOver();
	if (isGameOverConditionsFullfilled())
		gameOver();
}

void Game::render()
{
	window.clear(sf::Color::Black);

	// Main Part
	sf::RectangleShape gameLayout(sf::Vector2f(600, 600));
	gameLayout.setPosition(sf::Vector2f(0, 0));
	gameLayout.setFillColor(sf::Color::Black);
	window.draw(gameLayout);

	apple.render(&window);
	snake.render(&window);
	sideBar.render(&window);

	if (isPaused)
	{
		sf::Text pausedText;
		pausedText.setFont(font);
		pausedText.setString("Paused");
		pausedText.setPosition(sf::Vector2f(275, 10));
		window.draw(pausedText);
	}

	if (isGameOver)
	{
		sf::Text pausedText;
		pausedText.setFont(font);
		pausedText.setString("Game Over! Press R to restart...");
		pausedText.setPosition(sf::Vector2f(125, 10));
		window.draw(pausedText);
	}

	window.display();
}

void Game::gameOver()
{
	isGameOver = true;
	statistic.stopTimer();
}

bool Game::isGameOverConditionsFullfilled()
{
	if (snake.isCollideSelf())
		return true;
	return false;
}

void Game::switchPause()
{
	if (!isPaused) {
		isPaused = true;
		statistic.stopTimer();
	} else {
		isPaused = false;
		timer.restart();
		statistic.startTimer();
	}
}

void Game::restart()
{
	snake = std::deque<sf::Vector2f>{
		sf::Vector2f(280, 280), 
		sf::Vector2f(280, 320), 
		sf::Vector2f(280, 360)
	};
	if (isPaused) switchPause();
	isGameOver = false;
	timer.restart();
	statistic.reset();
}

void Game::moveAppleToRandimPosition()
{
	sf::Vector2f newApplePosition;
	std::mt19937 e{rand()};
	std::uniform_int_distribution<int> dist{0, 14};
	do 
	{
		newApplePosition = sf::Vector2f(dist(e) * 40, dist(e) * 40);
	} while(snake.hasPartAt(newApplePosition));
	apple.setPosition(newApplePosition);
}
