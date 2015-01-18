#include "gen.h"
#include "split.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
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

    if (!bracketed(word)) { // A true word (base case)
        ret.push_back(word);
    } else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        const Rule_collection & c = it->second;

        const Rule & r = c[nrand(c.size())];

        // Recursively deepen until a word replacement for a rule is found
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);

    }

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
