#include "palindrome.h"
#include <string>

using std::string;

bool isPalindrome(const std::string & s) {

    if (2 > s.size())
        return true;

    size_t begin = 0;
    size_t end = s.size() - 1;

    while (begin != end) {

        if (s[begin] != s[end])
            return false;

        begin++;
        if (begin == end) break;
        end--;

    }

    return true;

}
