#ifndef GUARD_find_h
#define GUARD_find_h

#include <vector>
#include <stdexcept>
#include <algorithm>

template<class In, class X> // Define template function with a type parameter
In find_(In begin, In end, const X& x) {

    while (begin != end && *begin != x)
        ++begin;

    return begin;

}

template <class In, class X>
In find_recursive(In begin, In end, const X& x) {

    if (begin == end || *begin == x)
        return begin;
    begin++;

    return find_recursive(begin, end, x);

    // an input iterator is one that supports incrementing and decrementing in
    // postfix and prefix , equality, * and equality of dereferenced items

}

#endif
