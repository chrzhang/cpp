#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

/*
Let the user input parameters to draw a right triangle.
*/
int main() {

    cout << "Enter base: ";
    int base;
    cin >> base;
    cout << endl;

    cout << "Enter height: " ;
    int height;
    cin >> height;
    cout << endl;

    // Determine length of intervals to place *
    int interval = base / (height - 1);
    int currInterval = interval;

    // Row-wise
    for (int row = 0; row != height; row++) {

        // Column-wise
        for (int col = 0; col != base; col++) {

            // If on the left or bottom
            if (0 == col || row == height - 1) {
                cout << "*";
            } else if (0 == col % currInterval) {
                cout << "*";
                currInterval += interval;
                break;
            }
            else
                cout << " ";

        }
        cout << endl;

    }

    return 0;

}
