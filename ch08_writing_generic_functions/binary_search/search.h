#ifndef GUARD_search_h
#define GUARD_search_h

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X&x) {

    while (begin < end) {

        Ran mid = begin + (end - begin) / 2;
        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;

    }

    return false;

    // A random access iterator has to be a bidirectional iterator and support
    // p + n, p - n, n + p, p - q, p[n], p < q, p > q, p <= q, p >= q
}

#endif
