#include "kwic.h"
#include <list>
#include <string>
#include <stdexcept>
#include <iostream>

using std::list;
using std::string;
using std::domain_error;

list<list<string>> generateRotations(const list<string> & words) {

    list<list<string>> ret;
    list<string> l = words;
    string empty; // Empty string to signify separator
    l.push_back(empty);
    ret.push_back(l);

    for (size_t i = 0; i < words.size() - 1; i++) {

        string head = l.front();
        l.pop_front();
        l.push_back(head);
        ret.push_back(l);

    }

    return ret;

}

bool compare(const list<string> & l1, const list<string> & l2) {

    if (l1.empty() || l2.empty()) {
        throw domain_error("line empty");
        return false;
    }

    // Go to the next word if the first words are identical
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while(0 == it1->compare(*it2)) {

        it1++;
        it2++;
        if (it1 == l1.end() || it2 == l2.end())
            return false;

    }

    return *it1 < *it2;

}

void unRotate(list<string> & words) {

    string empty;
    // Find the separator
    auto it = words.begin();
    for (; it != words.end(); ++it) {

        if (it->empty()) { // Found the separator
            words.push_back(empty);
            it = words.erase(it); // Next word
            words.splice(words.begin(), words, it, words.end());
            break;
        }

    }

}
