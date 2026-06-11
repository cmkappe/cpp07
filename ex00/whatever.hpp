#pragma once

// One function template works for any type T that supports comparisons and assignment
// compiler creates concrete versions when you call them with int, std::string, etc

template <typename T> const T& max(const T& a, const T& b){
    return (a > b) ? a : b;
}

template <typename T> const T& min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T> void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

/* Implement the following function templates:
• swap: Swaps the values of two given parameters. Does not return anything.
• min: Compares the two values passed as parameters and returns the smallest one. If they are equal, it returns the second one.
• max: Compares the two values passed as parameters and returns the greatest one. If they are equal, it returns the second one.
These functions can be called with any type of argument. 
The only requirement is that the two arguments must have the same type and must support all the comparison operators.
 */