#include "url.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given strings from user input, extract the URLs from them and store them as a
vector.
A URL is defined as a string containing URL characters and a :// to separate the
protocol and resource name.
*/
int main() {

    cout << "Enter a few lines of text with URLs in them: " << endl;
    vector<string> urls;

    string sAll, s;
    while (getline(cin, s)) {

        sAll += s;

    }

    cin.clear();

    urls = find_urls(sAll);

    for (auto it = urls.begin(); it != urls.end(); ++it) {
        cout << *it << endl;
    }

    return 0;

}
