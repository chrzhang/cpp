#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <stdexcept>
#include <algorithm>

template<class T> // Define template function with a type parameter
T median(std::vector<T> v) {

    // When a type depends on template params, and a member of that type is
    // needed (like size_type), use typename to treat the name as a type
    typedef typename std::vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");

    sort(v.begin(), v.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];

}

#endif
