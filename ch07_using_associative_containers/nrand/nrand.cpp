#include "nrand.h"
#include <cstdlib>
#include <stdexcept>
#include <cmath>

#define X_RAND_MAX 32767

using namespace std;

/*
Generate a random number from 0 to n, possibly greater than RAND_MAX.
*/
int nrand(int n) {

    if (n <= 0)
        throw domain_error("Argument to nrand is out of range");

    int r;
    if (n <= X_RAND_MAX) { // Unchanged from book

        const int bucket_size = X_RAND_MAX / n;


        do
            r = rand() / bucket_size;
        while (r >= n);

    } else {

        const int bucket_size = ceil(n / X_RAND_MAX);

        do {
            // Though this is a recursive call, it will always be the already
            // solved case where the argument is <= RAND_MAX
            const int bucket = nrand(X_RAND_MAX); // Choose a bucket
            // What's left is the true recursive call
            // bucket_size starts off as n / X_RAND_MAX and keeps getting
            // divided by X_RAND_MAX as the code recurses, shrinking
            // what's left to randomly pick from
            const int remainder = nrand(bucket_size);

            r = (bucket - 1) * bucket_size + remainder;
            // Get the result by multipling by the bucket #, how much that
            // bucket represents, and whatever's left to choose from
        } while (r >= n);

        // To best visualize this, say we want to roll a number out of 8 but
        // our current random number generator only supports a RAND_MAX of 1
        // To accurately roll out of 8, we can flip the coin, multiply the
        // result(1) by 4, flip, multiply the result(2) by 2, flip for result(1)
        // A flip returns either 0 or 1 (which is why RAND_MAX == 1)
        /*


                        0            0(4) + 0(2) + 0 = 0
                    0
                        1            0(4) + 0(2) + 1 = 1
               0
                        0            0(4) + 1(2) + 0 = 2
                    1
                        1            0(4) + 1(2) + 1 = 3

                        0            1(4) + 0(2) + 0 = 4
                    0
                        1            1(4) + 0(2) + 1 = 5
               1
                        0            1(4) + 1(2) + 0 = 6
                    1
                        1            1(4) + 1(2) + 1 = 7
        */
    }

    return r;

}
