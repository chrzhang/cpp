#ifndef GUARD_max_h
#define GUARD_max_h

#include <vector>
#include <stdexcept>
#include <algorithm>

template<class T> // Define template function with a type parameter
T max_(const T & left, const T & right) {

    return left > right ? left : right;

}

#endif
