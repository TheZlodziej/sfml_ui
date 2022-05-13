#include "Visual.hpp"

sf::UI::Visual::Visual(const std::vector<sf::Vector2f>& vertices):
	sf::ConvexShape(vertices.size())
{
	setShape(vertices);
}

sf::UI::Visual::~Visual()
{
}

void sf::UI::Visual::setShape(const std::vector<sf::Vector2f>& vertices)
{
	setPointCount(vertices.size());
	size_t index = 0u;

	for (const auto& vertex : vertices)
	{
		setPoint(index, vertex);
		index++;
	}

	sf::ConvexShape::update();
	setSize();
}

sf::Vector2f sf::UI::Visual::getSize() const
{
	return m_size;
}

void sf::UI::Visual::setSize()
{
	float maxX = 0.f;
	float maxY = 0.f;

	for (size_t i = 0u; i < getPointCount(); i++)
	{
		const auto point = getPoint(i);
		
		if (point.x > maxX)
			maxX = point.x;

		if (point.y > maxY)
			maxY = point.y;
	}

	m_size.x = maxX;
	m_size.y = maxY;
}

void sf::UI::Visual::update(const sf::RenderWindow& window, const sf::Time& time)
{
	// sf::ConvexShape::update();
	Node::update(window, time);
}

void sf::UI::Visual::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(static_cast<sf::ConvexShape>(*this));
	
	for (size_t i = 0; i < getChildrenCount(); i++)
	{
		auto parent = getParent();
		auto child = getChild<sf::Drawable>(i);
		
		if (child != nullptr)
		{
			target.draw(*child);
		}
	}
}
