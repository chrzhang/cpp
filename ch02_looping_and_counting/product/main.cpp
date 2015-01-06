#include <iostream>

/*
Find the product of the numbers from [1, 9].
*/
int main() {

    int product = 1;
    for (int i = 1; i < 10; i++) {

        product *= i;

    }
    std::cout << product << std::endl;

    return 0;

}
