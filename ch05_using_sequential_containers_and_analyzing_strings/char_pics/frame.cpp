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


vector<string> frame(const vector<string> & v) {

    vector<string> ret;
    string::size_type maxlen = width(v);

    // With one layer of padding and the border on each side, 4 extra characters
    string border(maxlen + 4, '*');

    ret.push_back(border); // Top

    for (vector<string>::size_type i = 0; i != v.size(); ++i) {

        // Write each row, padding with extra whitespace and framing with *
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");

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

    // Indices for left and right
    vector<string>::size_type i = 0, j = 0;

    // Until we've seen both rows from all pictures
    while (i != left.size() || j != right.size()) { // So long as there are rows

        string size;

        // If we haven't exhausted the left frame, keep adding
        if (i != left.size())
            s = left[i++];

        // Determine how much to pad
        s += string(width1 - s.size(), ' ');

        // If we haven't exhausted the right frame, add the right frame per row
        if (j != right.size())
            s += right[j++];

        ret.push_back(s);

    }

    return ret;

}
