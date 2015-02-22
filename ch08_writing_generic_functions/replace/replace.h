#ifndef GUARD_replace_h
#define GUARD_replace_h

template<class For, class X>
void replace_(For beg, For end, const X& x, const X& y) {

    while (beg != end) {

        if (*beg == x)
            *beg = y;
        ++beg;

    }

    // As a forward iterator, dereferencing, incrementing, equality, and
    // it->member should be supported (not decrementing)
    // ex. all standard-library containers
}

#endif
