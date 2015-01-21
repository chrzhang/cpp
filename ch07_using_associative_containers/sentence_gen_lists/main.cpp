#include "gen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {

    srand(time(NULL));

    ifstream myfile("input.txt");
    if (!myfile.is_open()) {
        cout << "Can't open file." << endl;
        return 1;
    }
    list<string> sentence = gen_sentence(read_grammar(myfile));
    myfile.close();

    list<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }

    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }

    cout << endl;

    return 0;

}
