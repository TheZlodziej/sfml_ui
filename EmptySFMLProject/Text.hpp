#pragma once

#include <SFML/Graphics/Text.hpp>

#include "Visual.hpp"

namespace sf::UI
{
	class Text:
		public Node,
		public sf::Text
	{
	};
}
