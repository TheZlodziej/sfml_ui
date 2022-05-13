#pragma once

#include <functional>

#include <SFML/Graphics/RectangleShape.hpp>

#include "Visual.hpp"
#include "IClickable.hpp"
#include "Text.hpp"

namespace sf::UI
{
    class Button :
        public Visual,
        public IClickable
    {
    // Functions
    public: Button(const std::function<void()>&, const std::function<void()> & = []() {}, const std::function<void()>& = []() {});
    public: virtual ~Button();

    // Inherited via IClickable
    public: virtual void checkMouseEvents(const sf::RenderWindow&) const override;

    // Inherited via Visual
    public: virtual void internalUpdate(const sf::RenderWindow&, const sf::Time&) override;
    };
}

