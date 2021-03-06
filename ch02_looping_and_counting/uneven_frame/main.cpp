#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

/*
Horizontal and vertical padding of the greeting frame are now independent.
*/
int main() {

    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    const string greeting = "Hello, " + name + "!";

    // Amount of blank padding around greeting
    const int horizontalPad = 2;
    // Amount of vertical padding around greeting
    const int verticalPad = 4;
    // Rows: top, bottom, greeting, top pad, bot pad
    const int rows = verticalPad * 2 + 3;
    // Columns: left pad, greeting, right pad, and frames
    const string::size_type cols = greeting.size() + horizontalPad * 2 + 2;

    cout << endl; // Separate output from input

    // Go row-wise
    for (int r = 0; r != rows; ++r) { // 'r' is destroyed after this loop

        // The column counter is up to greeting, which may be arbitrarily long
        // Use the type (size) intended to handle bigger greetings
        string::size_type c = 0;
        while (c != cols) {

            if (r == verticalPad + 1 && c == horizontalPad + 1) { // At start of greeting
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) // Frame
                    cout << "*";
                else // Padding
                    cout << " ";
                ++c; // Go left -> right
            }

        }

        cout << endl;

    }

    return 0;

}
