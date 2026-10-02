/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:05:01 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/02 21:37:59 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <string>

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
static const char* CYAN = "\033[36m";
// static const char* GREEN = "\033[32m";
// static const char* RED = "\033[31m";
// static const char* YELLOW = "\033[33m";

void    print_int(int& x){
    std::cout << BOLD << x << RESET << " ";
}

int main(void)
{
    std::cout << CYAN << BOLD << "\n--- Iter Test ---\n" << RESET << "\n";

    int arr[] = {1, 2, 3, 4, 5};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << BOLD << "Original array:" << RESET << "\n";
    for (size_t i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";
    
    std::cout << BOLD << "Applying iter to increment each element:" << RESET << "\n";
    iter(arr, arrSize, [](int& x) { x++; });
    // basically this void increment(int& x)
    // {
    //    x++;
    // }
    // then: iter(arr, arrSize, increment);
    for (size_t i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";

    std::cout << BOLD << "Applying iter to print each element:" << RESET << "\n";
    iter(arr, arrSize, [](const int& x) { std::cout << x << " "; });
    std::cout << "\n\n";

    std::cout << BOLD << "Printing with actual function:" << RESET << "\n";
    int arrFunct[] = {10, 20, 30};
    iter(arrFunct, 3, print_int);
    std::cout << "\n\n";

    std::cout << BOLD << "Const element array:" << RESET << "\n";
    const int arrConst[] = {1, 2, 3};
    iter(arrConst, 3, [](const int& x) {
        std::cout << x << " ";
    });
    std::cout << "\n\n";
    
    std::cout << BOLD << "String example - const reference cases:" << RESET << "\n";
    std::string arrStr[] = {"alpha", "beta", "gamma"};
    iter(arrStr, 3, [](const std::string& s) {
        std::cout << s << " ";
    });
    std::cout << "\n\n";
    
    std::cout << BOLD << "Edge case - zero-lenght:" << RESET << "\n";
    int arrNull[] = {1, 2, 3};
    // should do nothing and not crash
    iter(arrNull, 0, [](int&) {});
    
    std::cout << std::endl;

    return 0;
}
