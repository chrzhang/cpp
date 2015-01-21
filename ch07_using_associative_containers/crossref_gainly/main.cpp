#include "xref.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/*
Displays a cross-reference table for each word and which lines that word appears
on.
*/
int main() {

    // Input
    ifstream f("input.txt");
    if (!f.is_open()) {
        cout << "Can't open input file." << endl;
        return 1;
    }
    map<string, vector<int> > ret = xref(f);
    f.close();

    string::size_type maxlen = 0;
    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); it++) {

        maxlen = max(maxlen, (it->first).size());

    }

    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); it++) {

        cout << it->first << string(maxlen - (it->first).size(), ' ') << " | ";
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;

        ++line_it;
        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }

        cout << endl;

    }

    return 0;

}
