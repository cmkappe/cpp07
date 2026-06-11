/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:26:49 by ckappe            #+#    #+#             */
/*   Updated: 2026/06/12 01:07:02 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

// Construction with no parameter: Creates an empty array
template <typename T> Array<T>:: Array() : _array(nullptr), _len(0) {}

// Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default
template <typename T> Array<T>:: Array(unsigned int n) : _array(nullptr), _len(n){
    if (n > 0)
        _array = new T[_len];
}

// Copy constructor
// Modifying original or copy after copying must not affect the other
template <typename T>
Array<T>::Array(const Array &other) : _array(nullptr), _len(other._len) {
  if (_len > 0) {
    _array = new T[_len];
    for (unsigned int i = 0; i < _len; ++i) {
      _array[i] = other._array[i];
    }
  }
}

// Copy assignment operator
// Modifying original or copy after assignment must not affect the other
template <typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    delete[] _array;
    _len = other._len;
    _array = (_len > 0) ? new T[_len] : nullptr;
    for (unsigned int i = 0; i < _len; ++i)
      _array[i] = other._array[i];
  }
  return *this;
}

template <typename T> Array<T>::~Array() {
  if (_array != nullptr) {
    delete[] _array;
  }
}

//  A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.
template <typename T> unsigned int Array<T>::size() const { return _len; }
