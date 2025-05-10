#pragma once

#include <array>
#include <utility>

struct vec2
{
	float x, y;
};

struct triangle
{
	std::array<vec2, 3> points;
};

// Returns dot product (A · B) -> projection length of A onto B.
float dot(const vec2& a, const vec2& b);

// Projects all vertices onto the given axis and returns the min/max projection values.
std::pair<float, float> project_verts(const std::array<vec2, 3>& verts, const vec2& axis);

// Uses Separating Axis Theorem to detect triangle-triangle collision.
bool isColiding(const triangle& triangle1, const triangle& triangle2);