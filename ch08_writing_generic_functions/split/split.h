#ifndef GUARD_split_h
#define GUARD_split_h

#include <string>
#include <algorithm>

template <class Out>
void split(const std::string & str, Out os) {

    typedef string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end()) {

        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);

        if (i != str.end())
            *os++ = string(i, j);

        i = j;

    }

}

#endif
