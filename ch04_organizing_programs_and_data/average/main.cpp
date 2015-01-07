#include <iostream>
#include <vector>
#include <stdexcept>
#include "average.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::domain_error;

/*
Find the average of user-input numbers.
*/
int main() {

    vector<double> v;
    double x;
    while (cin >> x) {

        v.push_back(x);

    }

    try {
        double avg = average(v);
        cout << "Average: " << avg << endl;
    } catch (domain_error e) {
        cout << e.what();
        return -1;
    }

    return 0;
}
