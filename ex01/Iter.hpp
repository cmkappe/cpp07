#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T* array, const std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(const T* array, const std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

/* Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array, passed as a const value.
• The third one is a function that will be called on every element of the array.
 */