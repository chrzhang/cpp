#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::pair;
using std::endl;

/*
Count and display the frequency of distinct words in user input.
*/
int main() {

    map<string, int> wordMap;

    cout << "Enter words followed by an EOF: ";

    string word;
    while (cin >> word) {

       auto it = wordMap.find(word);
       // Check if word is already in the map
       if (wordMap.end() != it) { // Already read
           it->second++; // Increment count
       } else { // Insert word and count of 1 instead
           wordMap.insert(pair<string, int>(word, 1));
       }
    }

    // Iterate through map
    for (auto it = wordMap.begin(); it != wordMap.end(); it++) {

        cout << it->first << ": " << it->second << endl;

    }

    return 0;

}
