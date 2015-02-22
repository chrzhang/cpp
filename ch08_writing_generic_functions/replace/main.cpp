#include <iostream>
#include "replace.h"
#include <vector>
#include <assert.h>

using namespace std;

/*
Replace all contents of any container supporting iterator operations in both
read-write accesses matching an element with a new element.
*/
int main() {

    vector<int> v;

    for (int i = 0; i < 1000; i++) {
        v.push_back(0);
    }

    int oldStuff = 0;
    int newStuff = 1;
    replace_(v.begin(), v.end(), oldStuff, newStuff);

    for (int i = 0; i < 1000; i++) {
        assert(v[i] == 1);
    }

    return 0;

}
