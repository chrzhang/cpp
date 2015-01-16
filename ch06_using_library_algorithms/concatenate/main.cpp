#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

/*
Use library algorithm(s) to concatenate all strings in a vector<string>.
*/
int main() {

    string word;
    vector<string> words;

    cout << "Enter some words:" << endl;
    while (cin >> word)
        words.push_back(word);

    cin.clear();
    string empty;
    string all = accumulate(words.begin(), words.end(), empty);
    cout << "Result after concatenation:" << endl;
    cout << all << endl;

}
