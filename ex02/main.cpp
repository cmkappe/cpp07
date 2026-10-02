/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:11:17 by ckappe            #+#    #+#             */
/*   Updated: 2026/10/02 22:26:02 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

static const char* RESET = "\033[0m";
static const char* BOLD = "\033[1m";
static const char* CYAN = "\033[36m";
static const char* GREEN = "\033[32m";
static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";

int main(int, char**)
{
    bool ok = true;

    std::cout << CYAN << BOLD << "\n--- Array Test ---\n" << RESET << "\n";
    // Test default constructor and size
    Array<int> empty;
    if (empty.size() != 0)
    {
        std::cerr << RED << "default constructor failed" << RESET << std::endl;
        ok = false;
    }
    else
        std::cout << GREEN << "[OK] " << RESET << "Default constructor creates empty array" << std::endl;

    // Access on empty array must throw
    try
    {
        empty[0] = 42;
        std::cerr << RED << "empty array out-of-bounds did not throw" << RESET << std::endl;
        ok = false;
    }
    catch (const std::exception&)
    {
        std::cout << GREEN << "[OK] " << RESET << "Empty array out-of-bounds throws" << std::endl;
    }

    // Fill both arrays with identical random values
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Constructor with n must report the right size
    if (numbers.size() != MAX_VAL)
    {
        std::cerr << RED << "size() returned wrong value" << RESET << std::endl;
        ok = false;
    }
    else
        std::cout << GREEN << "[OK] " << RESET << "Sized constructor sets correct size" << std::endl;

    // Verify copy constructor copies all values
    Array<int> copy(numbers);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (copy[i] != mirror[i])
        {
            std::cerr << RED << "copy constructor did not copy values" << RESET << std::endl;
            ok = false;
            break;
        }
    }
    if (ok)
        std::cout << GREEN << "[OK] " << RESET << "Copy constructor copies values" << std::endl;

    // Verify deep copy: changes in original must not affect copy
    numbers[0] = -12345;
    if (copy[0] == numbers[0])
    {
        std::cerr << RED << "copy is not deep" << RESET << std::endl;
        ok = false;
    }
    else
        std::cout << GREEN << "[OK] " << RESET << "Copy constructor is deep" << std::endl;

    // Verify assignment operator and deep copy semantics
    Array<int> assigned;
    assigned = numbers;
    numbers[1] = -54321;
    if (assigned[1] == numbers[1])
    {
        std::cerr << RED << "assignment is not deep" << RESET << std::endl;
        ok = false;
    }
    else
        std::cout << GREEN << "[OK] " << RESET << "Assignment operator is deep" << std::endl;

    // Self-assignment should keep data intact
    int before = assigned[2];
    Array<int>* alias = &assigned;
    assigned = *alias;
    if (assigned[2] != before)
    {
        std::cerr << RED << "self-assignment failed" << RESET << std::endl;
        ok = false;
    }
    else
        std::cout << GREEN << "[OK] " << RESET << "Self-assignment keeps values intact" << std::endl;

    // Test const overload of operator[]
    const Array<int>& const_ref = assigned;
    int probe = const_ref[3];
    (void)probe;
    std::cout << GREEN << "[OK] " << RESET << "Const operator[] works" << std::endl;

    // Test out-of-bounds access with a negative index
    try
    {
        numbers[-2] = 0;
        std::cerr << RED << "negative index did not throw" << RESET << std::endl;
        ok = false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << GREEN << "[OK] " << RESET << "Negative index throws" << std::endl;
    }

    // Test out-of-bounds access at size limit
    try
    {
        numbers[MAX_VAL] = 0;
        std::cerr << RED << "index == size did not throw" << RESET << std::endl;
        ok = false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << GREEN << "[OK] " << RESET << "Index == size throws" << std::endl;
    }

    // Also verify the template works with another type
    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "42";
    if (words[0] != "hello" || words[1] != "42")
    {
        std::cerr << RED << "template with std::string failed" << RESET << std::endl;
        ok = false;
    }
    else
        std::cout << GREEN << "[OK] " << RESET << "Template works with std::string" << std::endl;

    delete [] mirror;
    if (!ok)
        return 1;
    std::cout << BOLD << YELLOW << "\nAll tests passed\n" << RESET << std::endl;
    return 0;
}
