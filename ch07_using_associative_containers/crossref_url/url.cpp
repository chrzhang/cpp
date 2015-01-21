#include "url.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::vector;
using std::string;

typedef string::const_iterator iter;

vector<string> find_urls(const string & s) {

    // Return a vector of URLs (protocol-name://resource-name)
    vector<string> ret;

    iter b = s.begin(), e = s.end();

    while (b != e) {

        // Look for one or more letters followed by ://
        b = url_beg(b, e); // Return e if not found
        if (b != e) { // Found something
            // Get the rest
            iter after = url_end(b, e); // Refer to 1 past the end
            ret.push_back(string(b, after)); // Store it
            b = after; // Keep going
        }

    }

    return ret;

}

iter url_end(iter b, iter e) {

    return find_if(b, e, not_url_char);

}

bool not_url_char(char c) {

    // Stuff in URLs in addition to alphanums
    // static - preserved across invocations of function
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // If it's alphanum or inside url_ch, it's a url char
    return !(isalnum(c) ||
             find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
    // find seeks c and returns url_ch.end() if not found

}

iter url_beg(iter b, iter e) {

    static const string sep = "://"; // Created once and immutable

    iter i = b;
    // Look for the separator
    // Search from i to e for the stuff in 'sep'
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {

        // Check that the separator isn't at the beginning or end
        if (i != b && i + sep.size() != e) {
            iter beg = i; // The ':' in the '://' separator (now look back)
            // Get letters for protocol-name
            while (beg != b && isalpha(beg[-1])) // Go back with indexing -1
                --beg;
            // Is there at least one char before and after
            // beg != i if beg has been decremented and we have gone backwards
            // For one valid character after the separator, increment i by the
            // size of the separator (3 for ://) to check that there's a char
            // valid for a URL afterwards
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        // If the separator wasn't part of a URL keep going
        i += sep.size();

    }

    return e;

}
