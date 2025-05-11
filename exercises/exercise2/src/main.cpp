/*	Exercise 2: Collisions
*	----------------------------------------------
*
*	Description:
*		- Renders two triangles using SFML, which are both controllable by the user.
*		- Highlights collision using color change based on Separating Axis Theorem.
* 
*	Controls:
*		Green triangle:
*			- Positional movement: WSAD.
*			- Speed increase: LSHFIT.
*		Blue triangle:
*			- Positional movement: ARROW KEYS.
*			- Speed increase: LCTRL.
*
*   Output:
*		- Visual window with two interactive triangles.
*		- Color indicates collision status.
*		- Control schema.
*
*   Notes:
*		- Triangles cannot leave the window bounds.
*		- Triangle logic is implemented in `triangle.h` and `triangle.cpp`.
*		- Visualization (SFML) logic is in `visualization.h` and `visualization.cpp`.
*		- All headers are in the `include/` directory.
*		- All source files are in the `src/` directory.
*		- Tests are located in the `tests/` directory.
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "visualization.h"

int main()
{
	const int widnow_width = 800, window_height = 600;
	Visualization vis(widnow_width, window_height);
	vis.run();
}