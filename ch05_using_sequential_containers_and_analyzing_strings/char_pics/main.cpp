#include "frame.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

    cout << "Enter strings followed by an EOF: ";

    vector<string> v;
    string s;
    while (cin >> s)
        v.push_back(s);

    cout << "Longest string has width " << width(v) << endl;

    v = frame(v);

    for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++) {

        cout << *it << endl;

    }

    cin.clear();

    cout << "Enter strings followed by an EOF: ";
    vector<string> a;
    while (cin >> s);
        a.push_back(s);

    a = frame(a);

    vector<string> vertical = vcat(v, a);
    vector<string> horizontal = hcat(v, a);

    cout << "Vertically catenated: " << endl;
    for (vector<string>::const_iterator it = vertical.begin();
         it != vertical.end(); it++) {

        cout << *it << endl;

    }

    cout << "Horizontally catenated: " << endl;
    for (vector<string>::const_iterator it = horizontal.begin();
         it != horizontal.end(); it++) {

        cout << *it << endl;

    }

    return 0;

}
