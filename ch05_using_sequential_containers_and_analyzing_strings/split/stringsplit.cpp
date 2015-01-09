#include "stringsplit.h"
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;

vector<string> split(const string & s) {

    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {

        // Ignore leading whitespace
        while (i != s.size() && isspace(s[i]))
            ++i;

        // Find the end of the word
        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j) { // Not adjacent whitespace
            ret.push_back(s.substr(i, j - i));
            i = j;
        }

    }

    return ret;

}
