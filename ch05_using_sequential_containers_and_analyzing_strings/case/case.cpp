#include "case.h"
#include <string>

using std::string;

bool isLowerCase(string & s) {

    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); i++) {

        if (s[i] < 'a' || s[i] > 'z')
            return false;

    }

    return true;

}

bool isUpperCase(string & s) {

    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); i++) {

        if (s[i] < 'A' || s[i] > 'Z')
            return false;

    }

    return true;

}
