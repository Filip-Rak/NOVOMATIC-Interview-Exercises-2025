#include "visualization.h"

void Visualization::process_events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Visualization::update()
{
	// Update delta time
	delta_time = delta_clock.restart().asSeconds();

	// Update triangles & shapes
	handle_movement(wasd_triangle, wasd_shape, wasd_controls);
	handle_movement(arrow_triangle, arrow_shape, arrow_controls);

	// Update outlines based on collision
	update_fill_colors();
}

void Visualization::handle_movement(triangle& triangle, sf::ConvexShape& shape, const std::vector<sf::Keyboard::Key>& controls)
{	
	// Pick speed
	float speed = triangle_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		speed = triangle_fast_speed;

	// Read input
	vec2 offset = { 0.f, 0.f };

	if (sf::Keyboard::isKeyPressed(controls[0])) offset.y -= speed;
	if (sf::Keyboard::isKeyPressed(controls[1])) offset.y += speed;
	if (sf::Keyboard::isKeyPressed(controls[2])) offset.x -= speed;
	if (sf::Keyboard::isKeyPressed(controls[3])) offset.x += speed;

	// Normalize speed to avoid diagonal movement boost
	float length = std::sqrt(offset.x * offset.x + offset.y * offset.y);
	if (length > 0.f) 
	{
		offset.x = (offset.x / length) * speed * delta_time;
		offset.y = (offset.y / length) * speed * delta_time;
	}
	else 
	{
		offset = { 0.f, 0.f };
	}

	// Prevetn the triangle from moving off-screen by using a bounding box

	// Apply offset to triangle
	for (auto& [x, y] : triangle.points)
	{
		x += offset.x;
		y += offset.y;
	}

	// Apply offset to shape
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		shape.setPoint(i, sf::Vector2f(triangle.points[i].x, triangle.points[i].y));
	}
}

void Visualization::update_fill_colors()
{
	if (isColiding(wasd_triangle, arrow_triangle))
	{
		wasd_shape.setFillColor(COLLISION_COLOR);
		arrow_shape.setFillColor(COLLISION_COLOR);
	}
	else
	{
		wasd_shape.setFillColor(WASD_COLOR);
		arrow_shape.setFillColor(ARROW_COLOR);
	}
}

void Visualization::render()
{
	// Clear previous frame
	window.clear(CLEAR_COLOR);

	// Draw both triangle shapes
	window.draw(wasd_shape);
	window.draw(arrow_shape);

	// Display new image
	window.display();
}

sf::ConvexShape Visualization::make_triangle_shape(const triangle& triangle, sf::Color color) const
{
	sf::ConvexShape shape;
	shape.setPointCount(triangle.points.size());

	for (std::size_t i = 0; i < triangle.points.size(); i++)
		shape.setPoint(i, sf::Vector2f(triangle.points[i].x, triangle.points[i].y));

	shape.setFillColor(color);
	return shape;
}

Visualization::Visualization(int window_width, int window_height)
	: window(sf::VideoMode(window_width, window_height), "Triangle Collision", sf::Style::Titlebar | sf::Style::Close),
	WINDOW_WIDTH(window_width), WINDOW_HEIGHT(WINDOW_HEIGHT)
{
	wasd_shape = make_triangle_shape(wasd_triangle, WASD_COLOR);
	arrow_shape = make_triangle_shape(arrow_triangle, ARROW_COLOR);

}

void Visualization::run()
{
	while (window.isOpen())
	{
		// React to user input
		process_events();

		// Update internal properties
		if (window.hasFocus())
			update();

		// Render the window
		render();
	}
}
