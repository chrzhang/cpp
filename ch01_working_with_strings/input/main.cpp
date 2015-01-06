#include <iostream>
#include <string>

/*
Take in, store, and display a user's name.
*/
int main() {

    std::cout << "Please enter your first name: ";

    std::string name; // A variable or a "named object"

    std::cin >> name; // Ignores leading whitespace, ends on whitespace

    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;

}
