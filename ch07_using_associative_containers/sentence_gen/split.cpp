#include "split.h"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using std::vector;
using std::string;
using std::find_if;

bool space(char c) {

    return isspace(c);

}

bool not_space(char c) {

    return !isspace(c);

}

vector<string> split(const string & str) {

    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();

    while (i != str.end()) {

        // find_if goes through i until str.end() looking for not_space
        // i becomes the iterator pointing to the agreeing element (non-WS char)
        i = find_if(i, str.end(), not_space); // Ignore leading blanks
        iter j = find_if(i, str.end(), space); // Find end

        if (i != str.end())
            ret.push_back(string(i, j)); // Construct a string from iters

        i = j;

    }

    return ret;

}
