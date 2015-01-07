#include "reader.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;

/*
Count the # of words in input and how many times each word occurred.
*/
int main() {

    vector<string> allWords;
    read(cin, allWords);

    cout << "You entered " << allWords.size() << " words." << endl;

    map<string, int> wordBins;

    for (auto it = allWords.begin(); it != allWords.end(); it++) {

        if (wordBins.end() == wordBins.find(*it)) {

            wordBins[*it] = 1;

        } else {

            wordBins[*it]++;

        }

    }

    for (auto it = wordBins.begin(); it != wordBins.end(); it++) {

        cout << it->first << ": " << it->second << endl;

    }

    return 0;

}
