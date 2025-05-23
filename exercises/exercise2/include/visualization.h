#pragma once

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "triangle.h"

class Visualization
{
	/* Attributes */

	// Window & timing
	sf::RenderWindow window;
	sf::Clock delta_clock;
	float delta_time = 0.f;

	// Triangles & Shapes
	triangle wasd_triangle = { {{
		{200.f, 200.f},
		{300.f, 200.f},
		{250.f, 300.f}
	}} };

	triangle arrow_triangle = { {{
		{500.f, 400.f},
		{600.f, 400.f},
		{550.f, 300.f}
	}} };

	sf::ConvexShape wasd_shape;
	sf::ConvexShape arrow_shape;

	// Colors
	const sf::Color WASD_COLOR = sf::Color(46, 204, 113);
	const sf::Color ARROW_COLOR = sf::Color(52, 152, 219);
	const sf::Color COLLISION_COLOR = sf::Color(231, 76, 60);
	const sf::Color CLEAR_COLOR = sf::Color::Black;

	// Constants: Controls
	const std::vector<sf::Keyboard::Key> wasd_controls = {
		sf::Keyboard::W,		// UP
		sf::Keyboard::S,		// DOWN
		sf::Keyboard::A,		// LEFT
		sf::Keyboard::D,		// RIGHT
		sf::Keyboard::LShift	// SPEED BOOST
	};	
	
	const std::vector<sf::Keyboard::Key> arrow_controls = {
		sf::Keyboard::Up,		// UP
		sf::Keyboard::Down,		// DOWN
		sf::Keyboard::Left,		// LEFT
		sf::Keyboard::Right,	// RIGHT
		sf::Keyboard::LControl	// SPEED BOOST
	};

	// Speed
	float triangle_normal_speed = 100.f;
	float triangle_fast_speed = 250.f;

public:
	/* Constructor */
	Visualization(int window_width, int window_height);

	/* Public Methods */
	void run();

private:
	/* Private Methods */

	// Processing
	void process_events();
	void update();
	void render();

	// Movement
	void handle_movement(triangle& triangle, sf::ConvexShape& shape, const std::vector<sf::Keyboard::Key>& controls);
	vec2 get_movement_vector(const std::vector<sf::Keyboard::Key> controls);
	bool will_fit_on_screen(const triangle& tri, const vec2& offset);
	void sync_shape_with_triangle(sf::ConvexShape& shape, triangle& tri);
	void update_fill_colors();
	
	// Utility
	sf::ConvexShape make_triangle_shape(const triangle& triangle, sf::Color color) const;
};