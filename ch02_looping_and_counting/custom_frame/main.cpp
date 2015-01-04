#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {

    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    const string greeting = "Hello, " + name + "!";

    // Prompt user for amount of padding
    cout << endl;
    cout << "Enter the amount of padding: ";
    int pad;
    cin >> pad;

    // Rows: top, bottom, greeting, top pad, bot pad
    const int rows = pad * 2 + 3;
    // Columns: left pad, greeting, right pad, and frames
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl; // Separate output from input

    // Go row-wise
    for (int r = 0; r != rows; ++r) { // 'r' is destroyed after this loop

        // The column counter is up to greeting, which may be arbitrarily long
        // Use the type (size) intended to handle bigger greetings
        string::size_type c = 0;
        while (c != cols) {

            if (r == pad + 1 && c == (unsigned) pad + 1) { // At start of greeting
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
