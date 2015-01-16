#include "url.h"
#include <iostream>
#include <string>
#include <vector>

#define EX62 0 // Turn to 1 to do Exercise 6-2

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

    if (EX62) {
        string blob;
        blob += "https://www.github.com is a website. ";
        blob += "So is https://mail.google.com ";
        blob += "A lot of my time disappears on http://www.reddit.com. ";
        blob += "http://a http://b http://c http://d ";
        urls = find_urls(blob);
        if (0 != urls[0].compare("https://www.github.com") ||
            0 != urls[1].compare("https://mail.google.com") ||
            0 != urls[2].compare("http://www.reddit.com.") ||
            0 != urls[3].compare("http://a") ||
            0 != urls[4].compare("http://b") ||
            0 != urls[5].compare("http://c") ||
            0 != urls[6].compare("http://d")) {
            cout << "Test failed." << endl;
        } else {
            cout << "Test passed." << endl;
        }
        urls.clear();
    }

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
