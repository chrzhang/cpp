#include "nrand.h"
#include <cstdlib>
#include <stdexcept>

using namespace std;

int nrand(int n) {

    if (n <= 0 || n > 32767)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = 32767 / n;
    int r;

    do
        r = rand() / bucket_size;
    while (r >= n);

    return r;

}
