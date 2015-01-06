#include <iomanip> // Defines setprecision (how many precision digits)
#include <ios> // Defines streamsize (represents sizes for IO)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // To sort the vector

#define MIDTERM_WEIGHT .2
#define FINAL_WEIGHT .4
#define HW_WEIGHT .4

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

typedef vector<double>::size_type vec_sz;

/*
Find the quarter of numbers with the highest values and the remaining quarters
from  user input.
*/
int main() {

    // String literals separated only by whitespace are automatically catenated
    cout << "Enter values followed by EOF: ";

    double x;
    vector<double> values;

    while (values.size() < 4) {

        // Attempt to read from cin (fails because no input or input wrong type)
        while (cin >> x) {

            values.push_back(x); // Append the new homework grade

        }

        if (values.size() < 4) {
            cout << "Enter at least 4 numbers." << endl;
        } else if (values.size() % 4 != 0) {
            // Since a quartile is "the quarter of the #s with the largest
            // values and so forth", there must be n numbers so that 4 | n
            cout << "There must be n numbers such that 4 | n." << endl;
            continue;
        }

    }

    sort(values.begin(), values.end());

    streamsize prec = cout.precision(); // Store orig. precision to restore

    cout << setprecision(3);
    // Highest quarter
    cout << "Q1: ";
    for (vec_sz i = 3 * (values.size() / 4); i != values.size(); i++) {

        cout << values[i] << " ";

    }
    cout << endl;

    // And the other quarters
    cout << "Q2: ";
    for (vec_sz i = 2 * (values.size() / 4); i != 3 * (values.size() / 4); i++) {

        cout << values[i] << " ";

    }
    cout << endl;


    cout << "Q3: ";
    for (vec_sz i = (values.size() / 4); i != 2 * (values.size() / 4); i++) {

        cout << values[i] << " ";

    }
    cout << endl;

    cout << "Q4: ";
    for (vec_sz i = 0; i != values.size() / 4; i++) {

        cout << values[i] << " ";

    }
    cout << endl;
    cout << setprecision(prec);

    return 0;

}
