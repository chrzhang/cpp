#include <iostream>
#include "search.h"
#include <vector>
#include <assert.h>

using namespace std;

/*
Search a container.
*/
int main() {

    vector<int> v;

    for (int i = 0; i < 1000; i++)
        v.push_back(i);

    // Binary search only works on non-decreasing containers

    for (int i = 0; i < 1000; i++)
        assert(binary_search(v.begin(), v.end(), i));

    return 0;

}
