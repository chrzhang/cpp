#include <iostream>
#include <vector>
#include <string>
#include "stringsplit.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

/*
Receive lines of input and store each word (separated by whitespace into a
vector of strings.
*/
int main() {

    string s;
    while (getline(cin, s)) { // Reads entire line and returns the stream

        vector<string> words = split(s);

        for (vector<string>::const_iterator it = words.begin(); it != words.end();
             it++) {

            cout << *it << endl;

        }

    }

    cin.clear();

    cout << "Now with the library doing all the work." << endl;
    while (cin >> s)
        cout << s << endl;

    return 0;

}
