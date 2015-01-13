#include "split.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/*
Read input lines and store words split by whitespace in a vector.
*/
int main() {

    string line;
    vector<string> words;
    while (getline(cin, line)) {

        vector<string> v = split(line);
        copy(v.begin(), v.end(), back_inserter(words));

    }

    cout << endl;

    typedef vector<string>::const_iterator iter;
    iter i = words.begin();
    while (i != words.end()) {

        cout << *i << " ";
        i++;

    }
    cout << endl;

}
