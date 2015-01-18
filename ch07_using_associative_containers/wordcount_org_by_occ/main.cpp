#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

/*
Count the number of times each word occurs in our input.
Display it in order of frequency rather than order of words.
*/
int main() {

    string s;
    // Keys are frequencies and values are lists of words with that freq
    map<int, list<string> > counters;

    // Maps with int values are initialized to 0 if they are not in the map
    while (cin >> s) {

        bool exists = false;
        // Must check up to all frequencies until word is found
        for (map<int, list<string> >::iterator it = counters.begin();
             it != counters.end(); it++) {

            list<string>::iterator match = find((it->second).begin(),
                                                (it->second).end(), s);
            if (match != (it->second).end()) {
                exists = true;
                // Remove it from the current frequency
                (it->second).erase(match);
                // Add it to the next frequency
                counters[it->first + 1].push_back(s);
                break;
            }

        }

        if (!exists)
            counters[1].push_back(s);

    }

    for (map<int, list<string> >::const_iterator it = counters.begin();
         it != counters.end(); ++it) {

        // Keys (it->first) are const lvalues
        for (list<string>::const_iterator word_it = (it->second).begin();
             word_it != (it->second).end(); word_it++) {

            cout << *word_it << "\t" << it->first << endl;

        }

    }

    return 0;

}
