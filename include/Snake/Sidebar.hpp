#include "Statistic.hpp"
#include "SFML/Graphics.hpp"

class Sidebar
{
public:
	Sidebar(Statistic *statistic);
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
	sf::Color backgroundColor;
	sf::Font font;
};
