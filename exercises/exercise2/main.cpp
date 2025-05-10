#include <iostream>
#include <SFML/Graphics.hpp>

#include "triangle.h"

sf::ConvexShape make_triangle_shape(const triangle& triangle, sf::Color color)
{
	sf::ConvexShape shape;
	shape.setPointCount(triangle.points.size());

	for (std::size_t i = 0; i < triangle.points.size(); i++)
	{
		shape.setPoint(i, sf::Vector2f(triangle.points[i].x, triangle.points[i].y));
	}

	shape.setFillColor(color);
	return shape;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Triangle Collision");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.display();
	}
}