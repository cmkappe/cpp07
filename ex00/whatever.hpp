#pragma once

#include <iostream>
#include <cstdint>
#include <string>


void swap(int& a, int& b);
int min(int a, int b);
int max(int a, int b);


template <typename T> T Max(T x, T y){
    return (x > y) ? x : y;
}

template <typename T> T Min(T x, T y){
    return (x < y) ? x : y;
}

template <typename T> void swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}
   

