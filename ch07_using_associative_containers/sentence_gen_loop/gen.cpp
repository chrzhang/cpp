#include "gen.h"
#include "split.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cstdlib> // For rand() and RAND_MAX

using namespace std;

Grammar read_grammar(istream & in) {

    Grammar ret;
    string line;

    while (getline(in, line)) {

        // Get a collection of input words
        vector<string> entry = split(line);

        // Store it in the grammar where the first input is the category
        // (and thus key) and the value is the rule collection
        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }

    return ret;

}

vector<string> gen_sentence(const Grammar & g) {

    vector<string> ret;
    // Generate a sentence using the <sentence> rule
    gen_aux(g, "<sentence>", ret);
    return ret;

}

bool bracketed(const string & s) {

    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';

}

void gen_aux(const Grammar & g, const string & word, vector<string> & ret) {

    // Find the associated rule for word
    Grammar::const_iterator it = g.find(word);
    if (it == g.end())
        throw logic_error("empty rule");
    const Rule_collection & c = it->second;
    const Rule & r = c[nrand(c.size())];

    // Store the components of the chosen rule
    vector<string> stringStack;

    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
        stringStack.push_back(*i); // 'back' or tail of vector is stack top

    // Stack now has a mix of some or none rules mixed with literals
    while (!stringStack.empty()) {

        // Remove any non-bracketed hard strings from the top of the stack
        while (!bracketed(stringStack.back())) {

            ret.push_back(stringStack.back());
            stringStack.pop_back();
            if (stringStack.empty()) break;

        }

        if (stringStack.empty()) break;

        // Take the top of the stack, find a rule for it, and replace
        Grammar::const_iterator git = g.find(stringStack.back());
        if (git == g.end())
            throw logic_error("empty rule");
        const Rule_collection & collection = git->second;
        const Rule & rule = collection[nrand(collection.size())];

        stringStack.pop_back();
        for (Rule::const_iterator i = rule.begin(); i != rule.end(); ++i)
            stringStack.push_back(*i); // 'back' or tail of vector is stack top

    }

    reverse(ret.begin(), ret.end());

}

int nrand(int n) {

    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do
        r = rand() / bucket_size;
    while (r >= n);

    return r;

}
