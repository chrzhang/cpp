#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
Iterators can be used on IO streams as well as containers.
Enter a bunch of ints and then end with Ctrl+D for an EOF (Linux).
*/
int main() {

    vector<int> v;

    // The iterator to the cin stream is analogous to begin()
    // The default(empty) istream_iterator<int>() is used as end() in that it
    // is returned when an EOF or error state appears
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // Copy the entire vector to stdout
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); // " " separates

    cout << endl;

    return 0;

}
