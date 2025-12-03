#pragma once

#include <iostream>

template <typename T, typename T2>

void iter(T *s, const size_t len, T2 func)
{
    for (size_t i = 0; i < len; i++)
        func(s[i]);
}
