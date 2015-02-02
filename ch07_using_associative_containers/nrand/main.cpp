#include "nrand.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        cout << nrand(2147483647) << "\n";
    }

    return 0;

}
