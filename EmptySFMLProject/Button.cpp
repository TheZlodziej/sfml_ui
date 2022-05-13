#include "Button.hpp"

#include <SFML/Window/Mouse.hpp>

sf::UI::Button::Button(const std::function<void()>& onClick, const std::function<void()>& onEnter, const std::function<void()>& onExit):
	Visual({ {0.f, 0.f}, {200.f, 0.f}, {200.f, 75.f}, {0.f, 75.f} }),
	IClickable(onClick, onEnter, onExit)
{
}

sf::UI::Button::~Button()
{
}

void sf::UI::Button::checkMouseEvents(const sf::RenderWindow& window) const
{
	const auto mousePos = getMousePosition(window);
	const auto& rectPos = getPosition();
	const auto& rectSize = getSize();

	bool isMouseInsideX = (mousePos.x > rectPos.x && mousePos.x < rectPos.x + rectSize.x);
	bool isMouseInsideY = (mousePos.y > rectPos.y && mousePos.y < rectPos.y + rectSize.y);

	if (isMouseInsideX && isMouseInsideY)
	{
		onEnter();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			onClick();
		}
	}
}

void sf::UI::Button::internalUpdate(const sf::RenderWindow& window, const sf::Time& time)
{
	checkMouseEvents(window);
}
