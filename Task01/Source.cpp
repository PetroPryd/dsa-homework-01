#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "Hello, SFML world!");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        Flower flower(window);
        flower.animate(window);
        window.display();
    }

    return 0;
}   