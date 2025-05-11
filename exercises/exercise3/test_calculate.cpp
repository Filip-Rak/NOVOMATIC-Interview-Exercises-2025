#include <string>
#include <cmath>
#include <catch2/catch_all.hpp>

#include "calculate.h"

TEST_CASE("Basic Integer Addition", "[calculate]")
{
	struct CustomInt
	{
		int val;
		static CustomInt identity() { return { 0 }; }
	};

	auto add = [](const CustomInt& a, const CustomInt& b) { return CustomInt{ a.val + b.val }; };

	auto result = calculate(4, CustomInt{2}, add);
	REQUIRE(result.val == 8);	// 0 + 2 + 2 + 2 + 2 = 8
}

TEST_CASE("String concatenation", "[calculate]")
{
	struct CustomString
	{
		std::string str;
		static CustomString identity() { return { "" }; };
	};

	auto concat = [](const CustomString& a, const CustomString& b) { return CustomString{ a.str + b.str }; };
	
	auto result = calculate(3, CustomString{ "Hi" }, concat);
	REQUIRE(result.str == "HiHiHi");
}

TEST_CASE("Vector Addition", "[calculate]")
{
	struct Vec2
	{
		float x, y;
		static Vec2 identity() { return { 0.f, 0.f }; }
	};
	auto add_vec2 = [](const Vec2& a, const Vec2& b) { return Vec2{ a.x + b.x, a.y + b.y }; };

	auto result = calculate(3, Vec2{ 1.f, 2.f }, add_vec2);
	REQUIRE(result.x == 3.f);
	REQUIRE(result.y == 6.f);
}

TEST_CASE("Zero repetitions", "[calculate]")
{
	struct CustomInt
	{
		int val;
		static CustomInt identity() { return { 0 }; }
	};

	auto add = [](const CustomInt& a, const CustomInt& b) { return CustomInt{ a.val + b.val }; };

	auto result = calculate(0, CustomInt{ 2 }, add);
	REQUIRE(result.val == CustomInt::identity().val);
}

TEST_CASE("Logical AND", "[calculate]")
{
	struct CustomBool
	{
		bool val;
		static CustomBool identity() { return CustomBool{ true }; };	// Identity for &&
	};

	auto logical_and = [](const CustomBool& a, const CustomBool& b) { return CustomBool{ a.val && b.val };  };
	
	REQUIRE(calculate(3, CustomBool{ true }, logical_and).val);
	REQUIRE_FALSE(calculate(3, CustomBool{ false }, logical_and).val);
}

TEST_CASE("Integer Multiplication", "[calculate]")
{
	struct CustomInt
	{
		int val;
		static CustomInt identity() { return { 1 }; }
	};

	auto multiply = [](const CustomInt& a, const CustomInt& b) { return CustomInt{ a.val * b.val }; };

	REQUIRE(calculate(4, CustomInt{ 2 }, multiply).val == pow(2, 4));
	REQUIRE(calculate(2, CustomInt{ 4 }, multiply).val == pow(4, 2));
	REQUIRE(calculate(16, CustomInt{ 2 }, multiply).val == pow(2, 16));
}