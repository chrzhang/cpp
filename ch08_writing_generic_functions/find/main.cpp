#include <iostream>
#include "find.h"
#include <vector>
#include <math.h>
#include <assert.h>

using namespace std;

int main() {

    vector<int> v;
    v.push_back(100);

    vector<int>::iterator it = find_(v.begin(), v.end(), 100);

    assert(*it == 100);

    for (int i = 0; i < 1000; i++) {

        v.push_back(i);

    }

    it = find_recursive(v.begin(), v.end(), 910);

    assert(*it == 910);

    return 0;

}
