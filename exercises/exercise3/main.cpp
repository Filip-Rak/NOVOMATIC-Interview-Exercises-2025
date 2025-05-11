/*
*   Exercise 3: Binary Operation
*   ----------------------------
*
*   Description:
*     Implements a generic `calculate()` function that applies a binary operation
*     repeatedly to a value, starting from the identity element.
*
*   Purpose:
*     - This file exists as an optional entry point for manual testing or demonstration.
*
*   Structure:
*     - The function `calculate` is implemented in `calculate.h` (header-only).
*     - All unit tests are located in `test_calculate.cpp` in the same directory.
*
*   Notes:
*     - This exercise does not take input nor return output.
*/


#include <iostream>
#include <exception>

#include "calculate.h"

struct Vec2 
{
	float x, y;
	static Vec2 identity() { return { 0.f, 0.f }; }
};

auto add_vec2 = [](const Vec2& a, const Vec2& b) {
	return Vec2{a.x + b.x, a.y + b.y}; };

void run_example()
{
	Vec2 pos = {1.f, 2.f};

	try
	{
		pos = calculate(3, pos, add_vec2);
		std::cout << pos.x << " " << pos.y << "\n";
	}
	catch (std::exception ex)
	{
		std::cerr << "Exception: " << ex.what() << "\n";
	}
}

// Main function left minimal per spec. See tests for further usage examples.
int main()
{
	// run_example();
}