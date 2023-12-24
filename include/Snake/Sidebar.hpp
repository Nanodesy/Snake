#pragma once
#include "Statistic.hpp"
#include "SFML/Graphics.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class Sidebar
{
public:
	Sidebar(Statistic *statistic, const Application::FontHolder& fontHolder);
	void render(sf::RenderWindow *window);

private:
	void renderLayout(sf::RenderWindow *window);
	void renderTitle(sf::RenderWindow *window);
	void renderTime(sf::RenderWindow *window);
	void renderStatistic(sf::RenderWindow *window);
	void renderHelp(sf::RenderWindow *window);
	void centerText(sf::Text *text);

private:
	Statistic *statistic;
	const Application::FontHolder& fontHolder;
	sf::Color backgroundColor;
};
