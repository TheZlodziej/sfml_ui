#pragma once

#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>

namespace sf::UI
{	
	class IClickable
	{
	// Variables
	public:
		std::function<void()> onClick;
		std::function<void()> onEnter;
		std::function<void()> onExit;
		// TODO: onClick -> if clicked wait for key release

	// Functions
	public: IClickable(std::function<void()>, std::function<void()>, std::function<void()>);
	public: virtual void checkMouseEvents(const sf::RenderWindow&) const = 0;

	public:	static sf::Vector2f getMousePosition(const sf::RenderWindow&);
	};
}

