#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <functional>

class PlayerInput
{
public:
	PlayerInput();
	void handleInputEvent(sf::Event *event);
	sf::Vector2f getPlayerMovementDirection();
	void onPausePressed(std::function<void()> onPausePressed);
	void onRestartPressed(std::function<void()> onRestartPressed);
	void onExitPressed(std::function<void()> onExitPressed);

private:
	bool isUpPressed;
	bool isLeftPressed;
	bool isDownPressed;
	bool isRightPressed;
	std::function<void()> _onPausePressed;
	std::function<void()> _onRestartPressed;
	std::function<void()> _onExitPressed;
};
