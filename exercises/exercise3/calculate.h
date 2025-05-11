#pragma once

#include <concepts>
#include <exception>

template <class T, class Op>
concept IsSupported = requires(T first, T second, Op operation)
{
	{ operation(first, second) } -> std::convertible_to<T>;
	{ T::identity() } -> std::convertible_to<T>;
};

template <class BinaryOp, class ValueType> 
	requires IsSupported<ValueType, BinaryOp>
ValueType calculate(int n, ValueType value, const BinaryOp& f) 
{
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n == 0) return ValueType::identity();
    if (n == 1) return value;

    ValueType half = calculate(n / 2, value, f);
    ValueType full = f(half, half);

    if (n % 2 == 0)
        return full;
    else
        return f(full, value);
}