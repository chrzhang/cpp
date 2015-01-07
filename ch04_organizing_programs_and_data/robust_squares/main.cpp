#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>

using std::streamsize;
using std::cout;
using std::endl;
using std::setw;

#define UPPER_BOUND 1000

/*
Calculate the squares of int values up to UPPER_BOUND while robustly adjusting
the output width.
*/
int main() {

    streamsize old_width = cout.width();

    // Output is 2 columns (value and the square)

    for (int i = 0; i <= UPPER_BOUND; i++) {

        cout << setw((streamsize) 3 + log10(UPPER_BOUND));
        cout << i;
        cout << setw((streamsize) 3 + 2 * log10(UPPER_BOUND));
        cout << pow(i, 2);
        cout << endl;

    }

    cout.width(old_width);

    return 0;

}
