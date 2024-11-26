#pragma once

#include <iostream>

template <typename T> void iter(T *array, size_t size, void (*function)(T const &)) {
    if (!array || !function)
        return;
    for (size_t i = 0; i < size; i++) {
        function(array[i]);
    }
}
