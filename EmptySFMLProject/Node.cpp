#include "Node.hpp"
#include <iostream>

sf::UI::Node::Node(sf::UI::Node* parent):
	m_parent(parent)
{
}

sf::UI::Node::~Node()
{
	for (auto& child : m_children)
	{
		delete child;
	}
}

void sf::UI::Node::internalUpdate(const sf::RenderWindow& window, const sf::Time& time)
{
}

void sf::UI::Node::update(const sf::RenderWindow& window, const sf::Time& time)
{
	internalUpdate(window, time);

	for (auto& child : m_children)
	{
		child->update(window, time);
	}
}

size_t sf::UI::Node::getChildrenCount() const
{
	return m_children.size();
}
