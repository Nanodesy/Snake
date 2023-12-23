#include "PlayerInput.hpp"

PlayerInput::PlayerInput()
{
}

sf::Vector2f PlayerInput::getPlayerMovementDirection()
{
	sf::Vector2f direction;
	if (isUpPressed)
		direction.y -= 1;
	if (isLeftPressed)
		direction.x -= 1;
	if (isDownPressed)
		direction.y += 1;
	if (isRightPressed)
		direction.x += 1;
	return direction;
}

void PlayerInput::handleInputEvent(sf::Event *event)
{
	sf::Event::EventType eventType = event->type;
	// Exit
	if (event->type == sf::Event::EventType::Closed || (eventType == sf::Event::EventType::KeyPressed && event->key.code == sf::Keyboard::Q && event->key.shift))
		if (_onExitPressed)
			_onExitPressed();

	if (eventType == sf::Event::EventType::KeyPressed || eventType == sf::Event::EventType::KeyReleased)
	{
		sf::Keyboard::Key eventKey = event->key.code;

		// Movement
		if (eventKey == sf::Keyboard::Up || eventKey == sf::Keyboard::W)
			this->isUpPressed = eventType == sf::Event::EventType::KeyPressed;
		if (eventKey == sf::Keyboard::Left || eventKey == sf::Keyboard::A)
			this->isLeftPressed = eventType == sf::Event::EventType::KeyPressed;
		if (eventKey == sf::Keyboard::Down || eventKey == sf::Keyboard::S)
			this->isDownPressed = eventType == sf::Event::EventType::KeyPressed;
		if (eventKey == sf::Keyboard::Right || eventKey == sf::Keyboard::D)
			this->isRightPressed = eventType == sf::Event::EventType::KeyPressed;

		// Pause
		if (eventType == sf::Event::KeyPressed && eventKey == sf::Keyboard::P)
			if (_onPausePressed)
				_onPausePressed();

		// Restart
		if (eventType == sf::Event::KeyPressed && eventKey == sf::Keyboard::R)
			if (_onRestartPressed)
				_onRestartPressed();
	}
}

void PlayerInput::onPausePressed(std::function<void()> onPausePressed)
{
	this->_onPausePressed = onPausePressed;
}

void PlayerInput::onRestartPressed(std::function<void()> onRestartPressed)
{
	this->_onRestartPressed = onRestartPressed;
}

void PlayerInput::onExitPressed(std::function<void()> onExitPressed)
{
	this->_onExitPressed = onExitPressed;
}
