#include <iostream>
#include <string>

int main() {

    std::cout << "Please enter your first name: ";

    std::string name; // A variable or a "named object"

    std::cin >> name; // Ignores leading whitespace, ends on whitespace

    // const promises these strings will not be changed
    const std::string greeting = "Hello, " + name + "!";
    // Use the constructor for strings with length and a filler char
    const std::string spaces(greeting.size(), ' ');
    // + used for string concatenation (+ is overloaded)
    const std::string second = "* " + spaces + " *"; // Frame with stars
    const std::string first(second.size(), '*'); // Top/bottom borders

    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std:: cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;

}
