#include "Sidebar.hpp"
#include <cmath>
#include <array>

Sidebar::Sidebar(
	Statistic *statistic,
	const Application::FontHolder &fontHolder) : statistic(statistic),
												 fontHolder(fontHolder),
												 backgroundColor(0xE6, 0xE6, 0xE6)
{
}

void Sidebar::render(sf::RenderWindow *window)
{
	renderLayout(window);
	renderTitle(window);
	renderTime(window);
	renderStatistic(window);
	renderHelp(window);
}

void Sidebar::renderLayout(sf::RenderWindow *window)
{
	sf::RectangleShape sideBar(sf::Vector2f(200, 600));
	sideBar.setPosition(sf::Vector2f(601, 0));
	sideBar.setFillColor(backgroundColor);
	window->draw(sideBar);
}

void Sidebar::renderTitle(sf::RenderWindow *window)
{
	sf::RectangleShape titleBox(sf::Vector2f(160, 40));
	titleBox.setPosition(sf::Vector2f(620, 20));
	titleBox.setFillColor(backgroundColor);
	titleBox.setOutlineColor(sf::Color::Black);
	titleBox.setOutlineThickness(1);
	window->draw(titleBox);

	sf::Text title;
	title.setFont(fontHolder.get(Resource::Font::Regular));
	title.setStyle(sf::Text::Bold);
	title.setCharacterSize(22);
	title.setString("Snake");
	title.setFillColor(sf::Color::Black);
	title.setPosition(sf::Vector2f(700, 40));
	centerText(&title);
	window->draw(title);
}

void Sidebar::renderTime(sf::RenderWindow *window)
{
	int hours = (statistic->getGameDurationMilliseconds() / 3600000) % 99;
	int minutes = (statistic->getGameDurationMilliseconds() / 60000) % 60;
	int seconds = (statistic->getGameDurationMilliseconds() / 1000) % 60;

	std::string hoursText = hours >= 10 ? std::to_string(hours) : "0" + std::to_string(hours);
	std::string minutesText = minutes >= 10 ? std::to_string(minutes) : "0" + std::to_string(minutes);
	std::string secondsText = seconds >= 10 ? std::to_string(seconds) : "0" + std::to_string(seconds);

	sf::Text timeTitle;
	timeTitle.setFont(fontHolder.get(Resource::Font::Regular));
	timeTitle.setCharacterSize(12);
	timeTitle.setStyle(sf::Text::Bold);
	timeTitle.setString("TIME:");
	timeTitle.setFillColor(sf::Color::Black);
	timeTitle.setPosition(sf::Vector2f(700, 92));
	centerText(&timeTitle);
	window->draw(timeTitle);

	sf::Text timeValue;
	timeValue.setFont(fontHolder.get(Resource::Font::Regular));
	timeValue.setCharacterSize(12);
	timeValue.setStyle(sf::Text::Bold);
	timeValue.setString(hoursText + ":" + minutesText + ":" + secondsText);
	timeValue.setFillColor(sf::Color::Black);
	timeValue.setPosition(sf::Vector2f(700, 108));
	centerText(&timeValue);
	window->draw(timeValue);
}

void Sidebar::renderStatistic(sf::RenderWindow *window)
{
	sf::Text statisticsTitle;
	statisticsTitle.setFont(fontHolder.get(Resource::Font::Regular));
	statisticsTitle.setCharacterSize(12);
	statisticsTitle.setStyle(sf::Text::Bold);
	statisticsTitle.setString("Statistics:");
	statisticsTitle.setFillColor(sf::Color::Black);
	statisticsTitle.setPosition(sf::Vector2f(700, 148));
	centerText(&statisticsTitle);
	window->draw(statisticsTitle);

	std::array<std::string, 3> statisticsArray = {
		"Snake size: " + std::to_string(statistic->getSnakeSize()),
		"Apples: " + std::to_string(statistic->getAppleCount()),
		"Apples per minute (APM): " + std::to_string(statistic->getApplesPerMinute())};

	for (u_long i = 0; i < statisticsArray.size(); i++)
	{
		sf::Text key;
		key.setFont(fontHolder.get(Resource::Font::Regular));
		key.setCharacterSize(12);
		key.setString(statisticsArray[i]);
		key.setFillColor(sf::Color::Black);
		centerText(&key);
		key.setPosition(sf::Vector2f(700, 164 + (i * 14)));
		window->draw(key);
	}
}

void Sidebar::renderHelp(sf::RenderWindow *window)
{
	sf::RectangleShape helpBox(sf::Vector2f(160, 120));
	helpBox.setPosition(sf::Vector2f(620, 460));
	helpBox.setFillColor(backgroundColor);
	helpBox.setOutlineColor(sf::Color::Black);
	helpBox.setOutlineThickness(1);
	window->draw(helpBox);

	sf::Text helpTitle;
	helpTitle.setFont(fontHolder.get(Resource::Font::Regular));
	helpTitle.setCharacterSize(12);
	helpTitle.setStyle(sf::Text::Bold);
	helpTitle.setString("Help:");
	helpTitle.setFillColor(sf::Color::Black);
	helpTitle.setPosition(sf::Vector2f(700, 470));
	centerText(&helpTitle);
	window->draw(helpTitle);

	std::array<std::pair<std::string, std::string>, 7> keybindings = {
		std::pair<std::string, std::string>("W/Up", "Move up"),
		std::pair<std::string, std::string>("A/Left", "Move left"),
		std::pair<std::string, std::string>("S/Down", "Move down"),
		std::pair<std::string, std::string>("D/Right", "Move right"),
		std::pair<std::string, std::string>("R", "Restart"),
		std::pair<std::string, std::string>("P", "Pause"),
		std::pair<std::string, std::string>("Shift+Q", "Exit")};

	for (u_long i = 0; i < keybindings.size(); i++)
	{
		sf::Text key;
		key.setFont(fontHolder.get(Resource::Font::Regular));
		key.setCharacterSize(12);
		key.setStyle(sf::Text::Bold);
		key.setString(keybindings[i].first + ":");
		key.setFillColor(sf::Color::Black);
		centerText(&key);
		key.setOrigin(sf::Vector2f(60, key.getOrigin().y));
		key.setPosition(sf::Vector2f(700, 486 + (i * 14)));
		window->draw(key);

		sf::Text description;
		description.setFont(fontHolder.get(Resource::Font::Regular));
		description.setCharacterSize(12);
		description.setString(keybindings[i].second);
		description.setFillColor(sf::Color::Black);
		centerText(&description);
		description.setOrigin(sf::Vector2f(0, description.getOrigin().y));
		description.setPosition(sf::Vector2f(700, 486 + (i * 14)));
		window->draw(description);
	}
}

void Sidebar::centerText(sf::Text *text)
{
	auto center = text->getGlobalBounds().getSize() / 2.f;
	auto localBounds = center + text->getLocalBounds().getPosition();
	auto rounded = sf::Vector2f{std::round(localBounds.x), std::round(localBounds.y)};
	text->setOrigin(rounded);
}
