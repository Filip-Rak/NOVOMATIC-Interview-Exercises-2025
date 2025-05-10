#pragma once

#include <array>

struct vec2
{
	float x, y;
};

struct triangle
{
	std::array<vec2, 3> points;
};

bool is_coliding(const triangle& triangle1, const triangle& triangle2);