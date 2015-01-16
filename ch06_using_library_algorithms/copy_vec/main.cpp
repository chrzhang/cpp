#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define CORRECTION_1 0
#define CORRECTION_2 1

using namespace std;

int main() {

    if (CORRECTION_1 && CORRECTION_2) {
        cout << "Only one correction or none may be active." << endl;
        return 1;
    }

    vector<int> u(10, 100);
    vector<int> v;

    if (CORRECTION_1)
        copy(u.begin(), u.end(), back_inserter(v));
    else if (CORRECTION_2) {
        for (auto it = u.begin(); it != u.end(); it++) {

            v.push_back(*it);

        }
    }
    else
        copy(u.begin(), u.end(), v.begin()); // Causes seg-fault

    cout << "u: " << endl;
    for (auto it = u.begin(); it != u.end(); it++) {

        cout << *it << " ";

    }

    cout << endl;

    cout << "v: " << endl;
    for (auto it = v.begin(); it != v.end(); it++) {

        cout << *it << " ";

    }

    cout << endl;

    return 0;

}
