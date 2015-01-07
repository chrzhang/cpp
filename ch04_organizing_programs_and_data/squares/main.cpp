#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>

using std::streamsize;
using std::cout;
using std::endl;
using std::setw;

/*
Calculate the squares of int values up to 100.
*/
int main() {

    streamsize old_width = cout.width();

    // Output is 2 columns (value and the square)

    for (int i = 0; i <= 100; i++) {

        cout << setw(5);
        cout << i;
        cout << setw(7);
        cout << pow(i, 2);
        cout << endl;

    }

    cout.width(old_width);

    return 0;

}
