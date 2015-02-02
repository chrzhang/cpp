#ifndef GUARD_copy_h
#define GUARD_copy_h

#include <vector>

template<class In, class Out> // Define template function with a type parameter
Out copy_(In begin, In end, Out dest) {

    while (begin != end)
        *dest++ = *begin++;

    return dest;

    // Provided that an iterator is for output alone, do not increment without
    // outputting for every increment. Be able to dereference iterator and able
    // to increment the iterators to make an output iterator (ex. back_inserter)
}

#endif
