#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using std::max;

/*
Read in lines an center them in a frame.
*/
int main() {

    list<string> allLines;
    list<string> framed;
    string line;
    string::size_type maxlen = 0;
    while (getline(cin, line)) { // Read line

        allLines.push_back(line);
        maxlen = max(maxlen, line.size());

    }

    string border = string(maxlen + 4, '*');
    framed.push_back(border);

    for (auto it = allLines.begin(); it != allLines.end(); it++) {

        string::size_type pad = 1 + (maxlen - it->size()) / 2;

        string l = "*" + string(pad, ' ') + *it + string(pad, ' ') + "*";
        framed.push_back(l);

    }

    framed.push_back(border);

    for (auto it = framed.begin(); it != framed.end(); it++)
        cout << *it << endl;

    return 0;

}
