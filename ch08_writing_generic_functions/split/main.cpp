#include <iostream>
#include "copy.h"
#include <vector>
#include <assert.h>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

    std::vector<int> v1;
    std::vector<int> v2;

    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    copy_(v1.begin(), v1.end(), back_inserter(v2));

    assert(equal(v1.begin(), v1.end(), v2.begin()));

    std::vector<int> v3;
    copy_(v2.begin(), v2.end(), back_inserter(v3));
    *(v3.begin()) = 1;

    assert(!equal(v3.begin(), v3.end(), v2.begin()));

    return 0;

}
