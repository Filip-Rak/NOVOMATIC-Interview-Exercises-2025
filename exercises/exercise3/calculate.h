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

    // Succesive powers of value: value^1, value^2, value^3, ...
    ValueType factor = value;   // Start from value^1

    // Binary exponentiation. Decompose n into powers of 2
    while (n > 0) 
    {
        // Current bit is set -> include this power of value in the result. 
        if (n % 2 == 1)
            result = f(result, factor);

        // Square the factor for next bit
        factor = f(factor, factor);

        // Shift to next bit == divice by 2
        n /= 2;
    }

    return result;
}