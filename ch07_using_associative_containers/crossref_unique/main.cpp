#include "xref.h"
#include <iostream>

using namespace std;

/*
Displays a cross-reference table for each word and which lines that word appears
on.
*/
int main() {

    map<string, vector<int> > ret = xref(cin);

    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); it++) {

        cout << it->first << " occurs on line(s): ";
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
