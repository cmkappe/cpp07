/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:05:01 by ckappe            #+#    #+#             */
/*   Updated: 2026/06/11 22:10:31 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

int main(void)
{
    std::cout << "\n--- Iter Test ---\n\n";

    int arr[] = {1, 2, 3, 4, 5};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array:\n";
    for (size_t i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";

    std::cout << "Applying iter to increment each element:\n";
    iter(arr, arrSize, [](int& x) { x++; });
    // basically this void increment(int& x)
    // {
    //    x++;
    // }
    // then: iter(arr, arrSize, increment);
    for (size_t i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";

    std::cout << "Applying iter to print each element:\n";
    iter(arr, arrSize, [](const int& x) { std::cout << x << " "; });
    std::cout << "\n";

    return 0;
}
