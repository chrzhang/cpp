#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::copy;
using std::back_inserter;

/*
Copy one vector to the back of another using copy() and iterator adaptors.
*/
int main() {

    cout << "Enter some integers: ";
    int x = 0;
    vector<int> v;
    while (cin >> x) {

        v.push_back(x);

    }

    cin.clear();
    cout << endl;

    cout << "Enter some integers again: ";
    vector<int> w;
    while (cin >> x) {

        w.push_back(x);

    }

    cin.clear();
    cout << endl;

    copy(w.begin(), w.end(), back_inserter(v));

    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    cout << endl;

    return 0;

}
