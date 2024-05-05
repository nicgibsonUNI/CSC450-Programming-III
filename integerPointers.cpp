#include <iostream>
#include <limits> 

int main() {
    // Declare variables to store user input
    int a, b, c;

    // Prompt user for input
    std::cout << "Please enter three integer values: ";

    // Loop until valid integers are entered
    while (!(std::cin >> a >> b >> c)) {
        // Clear error state
        std::cin.clear();   
        // Ignore remaining characters of incorrect input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid input. Please enter three integers: ";
    }

    // Declare pointers and allocate memory
    int* ptrA = nullptr;
    int* ptrB = nullptr;
    int* ptrC = nullptr;
    
    try {
        // Using 'new' operator to use dynamic memory allocation
        ptrA = new int(a); 
        ptrB = new int(b);
        ptrC = new int(c);
    } catch ( const std::bad_alloc& e) {
        // Handle memory allocation failures
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        // Free any allocated memory if partial allocation succeeded
        delete ptrA;
        delete ptrB;
        delete ptrC;
        return 1; // Exit program with error code
    }

    // Display variable values
    std::cout << "Variable values are: " << a << ", " << b << ", " << c << std::endl;
    // Dereference pointers and display pointer values
    std::cout << "Pointer values are: " << *ptrA << ", " << *ptrB << ", " << *ptrC << std::endl;

    // Free the allocated memory
    delete ptrA;
    delete ptrB;
    delete ptrC;

    return 0;                          
}