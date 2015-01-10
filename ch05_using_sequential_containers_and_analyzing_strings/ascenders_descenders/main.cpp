#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "scend.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::max;

/*
Find strings w/o ascending chars: bdfghklt
nor descending chars: qjpqy
*/
int main() {

    ifstream input("/usr/share/dict/words");
    size_t maxlen = 0;
    string longest;
    for (std::string line; getline(input, line);) {

        size_t i = 0;
        while (i != line.size()) {

            if (isAscendOrDescend(line[i]))
                break;
            i++;

        }
        if (i == line.size()) { // Checked whole string
            cout << line << endl;
            maxlen = max(maxlen, line.size());
            if (line.size() == maxlen)
                longest = line;
        }

    }

    cout << "Longest string w/o asc- or descending chars is: " << longest
         << endl;

    return 0;

}
