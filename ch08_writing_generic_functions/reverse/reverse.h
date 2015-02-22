#ifndef GUARD_reverse_h
#define GUARD_reverse_h

#include <utility>

template<class Bi>
void reverse_(Bi begin, Bi end) {

    while (begin != end) {
        --end;
        if (begin != end)
            std::swap(*begin++, *end);
    }

    // Bidirectional iterators meet forward iterator requirements and decrement-
    // ing of iterators (both postfix and prefix)
}

#endif
