#include "palindrome.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::max;

/*
Find all the palindromes in the input. Also, find the longest palindrome.
*/
int main() {

    // Run sudo apt-get install wamerican if not available
    size_t maxlen = 0;
    string longest;
    ifstream input("/usr/share/dict/words");
    for (std::string line; getline(input, line);) {

        if (isPalindrome(line)) {
            cout << line << endl;
            maxlen = max(maxlen, line.size());
            if (line.size() == maxlen)
                longest = line;
        }

    }

    cout << "Longest palindrome: " << longest << endl;

    return 0;

}
