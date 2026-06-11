/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:11:17 by ckappe            #+#    #+#             */
/*   Updated: 2026/06/12 00:59:27 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    bool ok = true;

    // Test default constructor and size
    Array<int> empty;
    if (empty.size() != 0)
    {
        std::cerr << "default constructor failed" << std::endl;
        ok = false;
    }
    else
        std::cout << "[OK] Default constructor creates empty array" << std::endl;

    // Access on empty array must throw
    try
    {
        empty[0] = 42;
        std::cerr << "empty array out-of-bounds did not throw" << std::endl;
        ok = false;
    }
    catch (const std::exception&)
    {
        std::cout << "[OK] Empty array out-of-bounds throws" << std::endl;
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
        std::cerr << "size() returned wrong value" << std::endl;
        ok = false;
    }
    else
        std::cout << "[OK] Sized constructor sets correct size" << std::endl;

    // Verify copy constructor copies all values
    Array<int> copy(numbers);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (copy[i] != mirror[i])
        {
            std::cerr << "copy constructor did not copy values" << std::endl;
            ok = false;
            break;
        }
    }
    if (ok)
        std::cout << "[OK] Copy constructor copies values" << std::endl;

    // Verify deep copy: changes in original must not affect copy
    numbers[0] = -12345;
    if (copy[0] == numbers[0])
    {
        std::cerr << "copy is not deep" << std::endl;
        ok = false;
    }
    else
        std::cout << "[OK] Copy constructor is deep" << std::endl;

    // Verify assignment operator and deep copy semantics
    Array<int> assigned;
    assigned = numbers;
    numbers[1] = -54321;
    if (assigned[1] == numbers[1])
    {
        std::cerr << "assignment is not deep" << std::endl;
        ok = false;
    }
    else
        std::cout << "[OK] Assignment operator is deep" << std::endl;

    // Self-assignment should keep data intact
    int before = assigned[2];
    Array<int>* alias = &assigned;
    assigned = *alias;
    if (assigned[2] != before)
    {
        std::cerr << "self-assignment failed" << std::endl;
        ok = false;
    }
    else
        std::cout << "[OK] Self-assignment keeps values intact" << std::endl;

    // Test const overload of operator[]
    const Array<int>& const_ref = assigned;
    int probe = const_ref[3];
    (void)probe;
    std::cout << "[OK] Const operator[] works" << std::endl;

    // Test out-of-bounds access with a negative index
    try
    {
        numbers[-2] = 0;
        std::cerr << "negative index did not throw" << std::endl;
        ok = false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "[OK] Negative index throws" << std::endl;
    }

    // Test out-of-bounds access at size limit
    try
    {
        numbers[MAX_VAL] = 0;
        std::cerr << "index == size did not throw" << std::endl;
        ok = false;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "[OK] Index == size throws" << std::endl;
    }

    // Also verify the template works with another type
    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "42";
    if (words[0] != "hello" || words[1] != "42")
    {
        std::cerr << "template with std::string failed" << std::endl;
        ok = false;
    }
    else
        std::cout << "[OK] Template works with std::string" << std::endl;

    delete [] mirror;
    if (!ok)
        return 1;
    std::cout << "All tests passed" << std::endl;
    return 0;
}
