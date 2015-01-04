#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {

    cout << "Enter side length: ";
    int length;
    cin >> length;
    cout << endl;

    // Row-wise
    for (int row = 0; row != length; row++) {

        // Column-wise
        for (int col = 0; col != length; col++) {

            // If on the left, top, right, or bottom
            if (0 == col || 0 == row || col == length - 1 || row == length - 1)
                cout << "*";
            else
                cout << " ";

        }
        cout << endl;

    }

    return 0;

}
