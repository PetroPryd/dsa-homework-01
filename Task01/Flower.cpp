#include "Flower.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Flower::Flower(sf::RenderWindow& window) : sunRadius(40.f), isgrowing(false)
{
    clock.restart();
    
}

void Flower::animate(sf::RenderWindow& window)
{
    sf::CircleShape sun(sunRadius);
    sun.setFillColor(sf::Color::Red);
    sun.setPosition({ 250.f, 10.f });

    sf::CircleShape shape(50.f);

    shape.setPosition({ 50.f, 50.f });
    shape.setFillColor(sf::Color::Yellow);
    sf::RectangleShape line({ 150.f, 5.f });
    line.setFillColor(sf::Color::Green);
    line.rotate(sf::degrees(90));
    line.setPosition({ 100.f, 170.f });

    shape.setOutlineThickness(20.f);
    shape.setOutlineColor(sf::Color(150, 100, 150));

    sf::ConvexShape convex;
    convex.setFillColor(sf::Color::Green);
    convex.setPointCount(4);

    convex.setPoint(0, { 150.f, 170.f });
    convex.setPoint(1, { 100.f, 230.f });
    convex.setPoint(2, { 140.f, 270.f });
    convex.setPoint(3, { 200.f, 190.f });
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > 1) {
            std::cout << "check" << std::endl;

            if (sun.getRadius() == 70.f) {
                isgrowing = false;
            }
            else {
                isgrowing = true;
            }
            

            if (isgrowing)
            {
                sunRadius += 30.f;
                std::cout << "grow" << std::endl;
            }
            else {
                std::cout << "do not grow" << std::endl;
                sunRadius -= 30.f;
            }

            sun.setRadius(sunRadius);
            clock.restart();
        }

        window.clear();
        window.draw(sun);
        window.draw(shape);
        window.draw(line);
        window.draw(convex);
        window.display();
    }
}
