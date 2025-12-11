#pragma once

#include <iostream>
#include <exception>
#include <iterator>
#include <algorithm>
#include <vector>

template <typename T >
typename T::iterator easyfind(T & container, int number_to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), number_to_find);

    if (it == container.end())
        throw std::runtime_error("Error : cant find number_to_find ");

    return it;
}