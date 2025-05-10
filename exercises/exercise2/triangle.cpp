#include "triangle.h"

float dot(const vec2& a, const vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

std::pair<float, float> project_verts(const std::array<vec2, 3>& verts, const vec2& axis)
{
	float min = dot(verts[0], axis);
	float max = dot(verts[0], axis);

	for (int i = 1; i < verts.size(); i++)
	{
		float projection = dot(verts[i], axis);

		if (projection < min) min = projection;
		else if (projection > max) max = projection;
	}

	return { min, max };
}

bool is_coliding(const triangle& triangle1, const triangle& triangle2)
{
	for (const auto& triangle : { triangle1, triangle2 })
	{
		for (int i = 0; i < triangle.points.size(); i++)
		{
			vec2 vert_a = triangle.points[i];
			vec2 vert_b = triangle.points[(i + 1) % triangle.points.size()];

			// Get perpendicular axis (normal).
			vec2 edge = { vert_b.x - vert_a.x, vert_b.y - vert_a.y };
			vec2 normal = { -edge.y, edge.x };

			// Project both triangles onto the axis.
			auto [min_1, max_1] = project_verts(triangle1.points, normal);
			auto [min_2, max_2] = project_verts(triangle2.points, normal);

			// If projections do not overlap -> separating axis found -> no collision.
			if (max_1 < min_2 || max_2 < min_1) return false;
		}
	}

	// No separating axis -> collision.
	return true;
}