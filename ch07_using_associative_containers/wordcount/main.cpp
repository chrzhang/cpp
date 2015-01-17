#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
Count the number of times each word occurs in our input.
*/
int main() {

    string s;
    map<string, int> counters;

    // Maps with int values are initialized to 0 if they are not in the map
    while (cin >> s)
        ++counters[s];

    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it) {

        // Keys (it->first) are const lvalues
        cout << it->first << "\t" << it->second << endl;

    }

    return 0;

}
