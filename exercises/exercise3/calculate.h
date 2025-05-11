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

    ValueType result = ValueType::identity();

    // Successive powers of value: value^1, value^2, value^4, value^8, ...
    ValueType factor = value;   // Start from value^1

    // Binary exponentiation
    // Process each bit of n from least to most significant
    while (n > 0) 
    {
        // Current bit is set -> include this factor in the result
        if (n % 2 == 1)
            result = f(result, factor);

        // Square the factor
        factor = f(factor, factor);

        // Shift to next bit
        n /= 2;
    }

    return result;
}