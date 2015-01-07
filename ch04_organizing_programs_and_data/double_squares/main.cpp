#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>

using std::streamsize;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;

#define UPPER_BOUND 100

/*
Calculate the squares of double values up to UPPER_BOUND while robustly adjusting
the output width.
*/
int main() {

    streamsize old_width = cout.width();

    cout << setprecision(5);

    // Output is 2 columns (value and the square)

    for (double d = 0; d <= UPPER_BOUND; d++) {

        cout << setw((streamsize) 3 + log10(UPPER_BOUND));
        cout << d;
        cout << setw((streamsize) 3 + 2 * log10(UPPER_BOUND));
        cout << pow(d, 2);
        cout << endl;

    }

    cout.width(old_width);

    return 0;

}
