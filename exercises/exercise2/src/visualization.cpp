#include "visualization.h"

Visualization::Visualization(int window_width, int window_height)
	: window(sf::VideoMode(window_width, window_height), "Triangle Collision", sf::Style::Titlebar | sf::Style::Close)
{
	wasd_shape = make_triangle_shape(wasd_triangle, WASD_COLOR);
	arrow_shape = make_triangle_shape(arrow_triangle, ARROW_COLOR);

	std::cout << "Controls:\n";
	std::cout << "Green Triangle: [WASD] Speed up: [LShift]\n";
	std::cout << "Blue Triangle: [ARROW KEYS] Speed up: [LCtrl]\n";
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

void Visualization::handle_movement(triangle& triangle, sf::ConvexShape& shape, const std::vector<sf::Keyboard::Key>& controls)
{	
	// Read input
	vec2 direction = get_movement_vector(controls);

	// Pick speed
	float speed = (sf::Keyboard::isKeyPressed(controls[4])) ? triangle_fast_speed : triangle_normal_speed;
	vec2 offset = {
		direction.x * speed * delta_time,
		direction.y * speed * delta_time,
	};

	if (!will_fit_on_screen(triangle, offset)) 
		return;

	// Apply offset to triangle
	for (auto& [x, y] : triangle.points)
	{
		x += offset.x;
		y += offset.y;
	}

	sync_shape_with_triangle(shape, triangle);
}

vec2 Visualization::get_movement_vector(const std::vector<sf::Keyboard::Key> controls)
{
	vec2 direction = { 0.f, 0.f };

	if (sf::Keyboard::isKeyPressed(controls[0])) direction.y -= 1.f;
	if (sf::Keyboard::isKeyPressed(controls[1])) direction.y += 1.f;
	if (sf::Keyboard::isKeyPressed(controls[2])) direction.x -= 1.f;
	if (sf::Keyboard::isKeyPressed(controls[3])) direction.x += 1.f;

	// Normalize speed to avoid diagonal movement boost
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length > 0.f)
	{
		direction.x /= length;
		direction.y /= length;
	}
	
	return direction;
}

bool Visualization::will_fit_on_screen(const triangle& tri, const vec2& offset)
{
	// Prevent the triangle from moving off-screen by using a bounding box
	float min_x = tri.points[0].x;
	float max_x = tri.points[0].x;
	float min_y = tri.points[0].y;
	float max_y = tri.points[0].y;

	// Get the initial bounding box
	for (int i = 1; i < tri.points.size(); i++)
	{
		min_x = std::min(min_x, tri.points[i].x);
		max_x = std::max(max_x, tri.points[i].x);
		min_y = std::min(min_y, tri.points[i].y);
		max_y = std::max(max_y, tri.points[i].y);
	}

	// Offset the bounding box
	float next_min_x = min_x + offset.x;
	float next_max_x = max_x + offset.x;
	float next_min_y = min_y + offset.y;
	float next_max_y = max_y + offset.y;

	// Check if the future boudning box will stay within the window
	return !(next_min_x < 0.f || next_max_x >(float)window.getSize().x ||
		next_min_y < 0.f || next_max_y >(float)window.getSize().y);
}

void Visualization::sync_shape_with_triangle(sf::ConvexShape& shape, triangle& tri)
{
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		shape.setPoint(i, sf::Vector2f(tri.points[i].x, tri.points[i].y));
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

sf::ConvexShape Visualization::make_triangle_shape(const triangle& triangle, sf::Color color) const
{
	sf::ConvexShape shape;
	shape.setPointCount(triangle.points.size());

	for (std::size_t i = 0; i < triangle.points.size(); i++)
		shape.setPoint(i, sf::Vector2f(triangle.points[i].x, triangle.points[i].y));

	shape.setFillColor(color);
	return shape;
}
