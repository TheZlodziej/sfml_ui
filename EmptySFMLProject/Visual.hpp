#pragma once

#include "Node.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

namespace sf::UI
{
	class Visual :
		public Node,
		public sf::ConvexShape
	{
	// Variables
	private: sf::Vector2f m_size;

	// Functions
	public:	 Visual(const std::vector<sf::Vector2f>&);
	public:  virtual ~Visual();
	public:	 virtual void setShape(const std::vector<sf::Vector2f>&); // default is rectangle size 200 x 75
	public:  sf::Vector2f getSize() const; // returns coordinates of max x value and max y value (from all points of the shape)
	private: void setSize();
	public:  void update(const sf::RenderWindow& window, const sf::Time& time);

	// Inherited via sf::ConvexShape
	protected: virtual void draw(RenderTarget& target, RenderStates states) const override;
	};
}

