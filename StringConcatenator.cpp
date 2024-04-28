#include <iostream>
#include <string>

int main() {
    for (int i = 0; i < 3; ++i) {
        std::string input1, input2; // Declare two variables to store user inputs

        std::cout << "Enter a first string: ";
        std::getline(std::cin, input1); // Read first string from input

        std::cout << "Enter a second string: ";
        std::getline(std::cin, input2); // Read second string from input

        // Concatenate the two strings into new string
        std::string result = input1 + " " + input2;
        std::cout << "Concatenated String: " << result << std::endl; //Output to console
    }
    return 0;
}