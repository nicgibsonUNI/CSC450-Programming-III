#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

// Function to append data to file
void appendToFile(const std::string& filename, const std::string& data) {
    std::ofstream outfile;
    // Open the file in append mode
    outfile.open(filename, std::ios_base::app);
    if (!outfile) {
        throw std::ios_base::failure("Failed to open file for appending.");
    }
    // Write the data to the file and add a new line
    outfile << data << '\n'; 
    outfile.close();
}

// Function to reverse the content of a file and write it to another file
void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream infile(inputFilename);
    if (!infile) {
        throw std::ios_base::failure("Failed to open input file for reading.");
    }

    std::ofstream outfile(outputFilename);
    if (!outfile) {
        throw std::ios_base::failure("Failed to open output file for writing.");
    }

    // Read the entire content of the input file into a string
    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    // Reverse the content of the string  
    std::reverse(content.begin(), content.end());
    // Write the reversed content to the output file
    outfile << content;
    infile.close();
    outfile.close();
}

int main() {
    try {
        std::string userInput;
        std::string inputFile = "CSC450_CT5_mod5.txt";
        std::string reversedFile = "CSC450-mod5-reverse.txt"; 

        // Prompt user and get input
        std::cout << "Enter text to append to the file: ";
        std::getline(std::cin, userInput);

        // Input validation
        if (userInput.empty()) {
            throw std::invalid_argument("Input cannot be empty. Please enter some text.");
        }

        // Call the function to append user input to the file
        appendToFile(inputFile, userInput);

        // Call the function to reverse the content of the file and store it in other file
        reverseFileContent(inputFile, reversedFile);

        // Notify the user that operations are complete
        std::cout << "User input appended to " << inputFile << " and reversed content stored in " << reversedFile << std::endl;

    } catch (const std::exception& e) {
        // Handle exceptions and print the error message
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Returns non-zero value to indicate an error
    }

    return 0;
}