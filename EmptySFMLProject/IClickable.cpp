#include "IClickable.hpp"

#include <SFML/Window/Mouse.hpp>

sf::UI::IClickable::IClickable(std::function<void()> onClick, std::function<void()> onEnter, std::function<void()> onExit):
	onClick(onClick),
	onEnter(onEnter),
	onExit(onExit)
{}

sf::Vector2f sf::UI::IClickable::getMousePosition(const sf::RenderWindow& window)
{
	return static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
}