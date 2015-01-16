#include "frame.h"
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string> & v) {

    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());

    return maxlen;

}


vector<string> frame(const vector<string> & v) { // This time with iterators

    vector<string> ret;
    string::size_type maxlen = width(v);

    // With one layer of padding and the border on each side, 4 extra characters
    string border(maxlen + 4, '*');

    ret.push_back(border); // Top

    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {

        ret.push_back("* " + *it + string(maxlen - it->size(), ' ') + " *");

    }

    ret.push_back(border); // Bottom

    return ret;

}

vector<string> vcat(const vector<string> & top, const vector<string> & bottom) {

    // Vertically catenate two frames
    vector<string> ret = top;
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end();
         ++it) {

        ret.push_back(*it);

    }

    // Shorthanded:
    // ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;

}

vector<string> hcat(const vector<string> & left, const vector<string> & right) {

    vector<string> ret;
    // Leave a space between pictures
    string::size_type width1 = 1 + width(left);

    // Use iterators this time round
    vector<string>::const_iterator itL, itR;
    itL = left.begin();
    itR = right.begin();

    while (itL != left.end() || itR != right.end()) {

        string s;
        if (itL != left.end())
            s = *(itL++);

        s += string(width1 - s.size(), ' ');

        if (itR != right.end())
            s += *(itR++);

        ret.push_back(s);

    }

    return ret;

}
