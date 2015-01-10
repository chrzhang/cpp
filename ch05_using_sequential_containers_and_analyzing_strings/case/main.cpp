#include <iostream>
#include "case.h"
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main() {

    string word;
    list<string> lower;
    list<string> upper;

    while (cin >> word) {

        if (isLowerCase(word))
            lower.push_back(word);
        else if (isUpperCase(word))
            upper.push_back(word);

    }

    for (list<string>::const_iterator it = lower.begin(); it != lower.end();
         it++) {

        cout << *it << " ";

    }

    cout << endl;

    for (list<string>::const_iterator it = upper.begin(); it != upper.end();
         it++) {

        cout << *it << " ";

    }

    cout << endl;

    return 0;

}
