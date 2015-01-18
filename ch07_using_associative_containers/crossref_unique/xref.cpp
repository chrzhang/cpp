#include "xref.h"
#include "split.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Note the space between > >
map<string, vector<int> > xref(istream & in,
                               vector<string> find_words(const string &)
                               /* = split */ ) { // default arg is split

    // The default argument may be omitted so either
    // xref(cin) or xref(cin, find_urls) is okay
    string line;
    int line_number = 0;
    // Each word is the key and the value is a container of line #s
    map<string, vector<int> > ret;

    while (getline(in, line)) {
        ++line_number;
        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it) {

            // Do not repeat line number if that word has already occurred
            if (find(ret[*it].begin(), ret[*it].end(), line_number) !=
                ret[*it].end())
                continue;

            // For each word in the current line, reference it as a key to the
            // map and include the line number in its value
            ret[*it].push_back(line_number);

        }

    }

    return ret;

}
