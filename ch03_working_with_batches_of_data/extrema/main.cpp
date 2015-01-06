#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/*
Report the length of the longest and shortest string in input.
*/
int main() {

    string word;
    vector<string> words;

    cout << "Enter some words: ";

    while (words.empty()) {

        while (cin >> word) {

            words.push_back(word);

        }

        if (words.empty())
            cout << "Please enter some words." << endl;
    }

    // Initialize shortest and longest string to be the first string
    auto shortestString = words.begin();
    auto longestString = words.begin();

    for (auto it = words.begin(); it != words.end(); it++) {

       if (it->size() < shortestString->size()) {
            shortestString = it;
        }
        if (it->size() > longestString->size()) {
            longestString = it;
        }

    }

    cout << endl;

    cout << "The longest string is <" << *longestString << "> with "
         << longestString->size() << " characters." << endl;
    cout << "The shortest string is <" << *shortestString << "> with "
         << shortestString->size() << " characters." << endl;

    return 0;

}
