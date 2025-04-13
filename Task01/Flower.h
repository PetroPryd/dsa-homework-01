#pragma once
#include <SFML/Graphics.hpp>

class Flower {
private:
	sf::Clock clock;
	float sunRadius;
	bool isgrowing;
public:
	Flower(sf::RenderWindow& window);
	void animate(sf::RenderWindow& window);
};