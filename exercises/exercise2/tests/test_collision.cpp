#include <catch2/catch_all.hpp>

#include "triangle.h"

TEST_CASE("Test 1: Identical triangles", "[is_colliding]")
{
	triangle t1 = { {{{0, 0}, {1, 0}, 0, 1}} };
	triangle t2 = { {{{0, 0}, {1, 0}, 0, 1}} };

	bool colides = isColiding(t1, t2);
	REQUIRE(colides);
}

TEST_CASE("Test 2: Triangles far apart", "[is_colliding]")
{
	triangle t1 = { {{{0, 0}, {1, 0}, 0, 1}} };
	triangle t2 = { {{ {10, 10}, {11, 10}, {10, 11} }} };

	bool colides = isColiding(t1, t2);
	REQUIRE_FALSE(colides);
}

TEST_CASE("Test 3: Partial overlap", "[is_colliding]")
{
	triangle t1 = { {{{0, 0}, {1, 0}, 0, 1}} };
	triangle t2 = { {{ {0.5, 0.5}, {1.5, 0.5}, {0.5, 1.5} }} };

	bool colides = isColiding(t1, t2);
	REQUIRE(colides);
}

TEST_CASE("Test 4: Touching on edge", "[is_colliding]")
{
	triangle t1 = { {{{0, 0}, {1, 0}, 0, 1}} };
	triangle t2 = { {{ {0.5, 0.5}, {1.5, 0.5}, {0.5, 1.5} }} };

	bool colides = isColiding(t1, t2);
	REQUIRE(colides);
}

TEST_CASE("Test 5: Single vertex overlap", "[is_colliding]")
{
	triangle t1 = { {{ {1, 1}, {2, 1}, {1, 2} }} };
	triangle t2 = { {{ {1, 1}, {0, 2}, {2, 2} }} };

	bool colides = isColiding(t1, t2);
	REQUIRE(colides);
}

TEST_CASE("Test 6: Close not overlapping", "[is_colliding]")
{
	triangle t1 = { {{ {4, 1}, {3, 1}, {2, 2} }} };
	triangle t2 = { {{ {2, 1}, {1, 2}, {1, 3} }} };

	bool colides = isColiding(t1, t2);
	REQUIRE_FALSE(colides);
}