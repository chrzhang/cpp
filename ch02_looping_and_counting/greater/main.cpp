#include <iostream>

int main() {

    std::cout << "Enter a number: ";
    int n1;
    std::cin >> n1;
    std::cout << std::endl;

    std::cout << "Enter a number: ";
    int n2;
    std::cin >> n2;
    std::cout << std::endl;

    if (n1 > n2)
        std::cout << n1 << " is greater than " << n2 << std::endl;
    else if (n2 > n1)
        std::cout << n2 << " is greater than " << n1 << std::endl;
    else
        std::cout << n1 << " is equal to " << n2 << std::endl;

    return 0;

}
