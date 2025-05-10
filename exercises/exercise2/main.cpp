#include <iostream>
#include <SFML/Graphics.hpp>

#include "visualization.h"

int main()
{
	const int widnow_width = 800, window_height = 600;
	Visualization vis(widnow_width, window_height);
	vis.run();
}