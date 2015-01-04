#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {

    cout << "Enter horizontal side length: ";
    int horizontalLength;
    cin >> horizontalLength;
    cout << endl;

    cout << "Enter vertical side length: " ;
    int verticalLength;
    cin >> verticalLength;
    cout << endl;

    // Row-wise
    for (int row = 0; row != verticalLength; row++) {

        // Column-wise
        for (int col = 0; col != horizontalLength; col++) {

            // If on the left, top, right, or bottom
            if (0 == col || 0 == row || col == horizontalLength - 1
                         || row == verticalLength - 1) {
                cout << "*";
            }
            else
                cout << " ";

        }
        cout << endl;

    }

    return 0;

}
