#include "reader.h"
#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::vector;
using std::string;

istream & read(istream & is, vector<string> & words) {

    if (is) {
        words.clear();

        string w;
        while (is >> w)
            words.push_back(w);

        is.clear();
    }

    return is;

}
