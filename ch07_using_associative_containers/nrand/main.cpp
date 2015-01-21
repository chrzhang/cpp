#include "nrand.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    srand(time(NULL));
    cout << nrand(2147483647) << endl;
    return 0;

}
