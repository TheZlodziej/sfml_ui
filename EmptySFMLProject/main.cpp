#include <iostream>

#include <SFML/Graphics.hpp>

#include "Button.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(120u);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::UI::Node root;

    auto btn = root.addChild<sf::UI::Button>([&]() { window.close(); });

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        root.update(window, sf::Time());

        window.clear();
        window.draw(shape);

        for (size_t i = 0; i < root.getChildrenCount(); i++)
        {
            auto node = root.getChild<sf::Drawable>(i);

            if (node != nullptr)
                window.draw(*node);
        }

        window.display();
    }

    return 0;
}