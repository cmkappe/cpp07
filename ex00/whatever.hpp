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
