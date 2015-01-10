#include "kwic.h"
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::list;
using std::string;
using std::endl;
using std::istringstream;
using std::max;
using std::domain_error;

/*
Get a permuted index of input lines. Reference keword-in-context or kwic to
research. Run with inputs to get samples.
*/
int main() {

    cout << "Enter lines: " << endl;
    string line;
    list<list<string>> rotations;

    while (getline(cin, line)) {

        if (line.empty())
            continue;

       string word;
        list<string> words;

        istringstream iss(line);
        while (iss >> word) {
            words.push_back(word);
        }

        list<list<string>> r = generateRotations(words);
        rotations.insert(rotations.end(), r.begin(), r.end());

    }

    try {
        rotations.sort(compare); // Sort lines
    } catch (domain_error e) {
        cout << e.what();
        return -1;
    }

    for (auto it = rotations.begin(); it != rotations.end(); it++)
        unRotate(*it); // Unrotate

    // Find out width of left half
    string::size_type maxlen = 0;
    for (auto it = rotations.begin(); it != rotations.end(); it++) {

        string::size_type len = 0;
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {

            len += it2->size();

        }
        len += it->size(); // # spaces = # words
        maxlen = max(maxlen, len);

    }

    for (auto it = rotations.begin(); it != rotations.end(); it++) {

        string::size_type lenSoFar = 0;
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {

            if (it2->empty()) {
                // Output remaining spaces as padding to align output
                cout << string(maxlen - lenSoFar, ' ');
            }
            cout << *it2 << " ";
            lenSoFar += 1 + it2->size();

        }
        cout << endl;

    }

    return 0;

}
