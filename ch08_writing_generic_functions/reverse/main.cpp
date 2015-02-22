#include <iostream>
#include "reverse.h"
#include <vector>
#include <assert.h>

using namespace std;

/*
Reverse a container.
*/
int main() {

    vector<int> v;

    for (int i = 0; i < 1000; i++)
        v.push_back(i);

    reverse_(v.begin(), v.end());

    for (int i = 0; i < 1000; i++)
        assert(v[i] == 999 - i);

    return 0;

}
