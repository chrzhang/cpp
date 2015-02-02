#include <iostream>
#include "max.h"
#include <vector>
#include <math.h>
#include <assert.h>

using namespace std;

int main() {

    int x = 3;
    int y = 4;

    assert(max_(x,y) == 4);
    assert(max_(y,x) == 4);

    return 0;

}
