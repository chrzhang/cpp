#include <iostream>
#include <string>
#include "palindrome.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

/*
Return whether user input is a palindrome.
*/
int main() {

    string word;
    while (cin >> word) {

        if (is_palindrome(word))
            cout << "It's a palindrome!" << endl;

        word.clear();

    }

    return 0;

}
