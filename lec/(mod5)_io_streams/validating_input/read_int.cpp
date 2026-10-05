#include <iostream>
#include <limits>

int main() {
    int val = 0;
    std::cout << "Enter a single integer: ";
    std::cin >> val;

    while (!std::cin.fail()) {  // Data was successfully read.
        std::cout << "You entered: " << val << std::endl;

        // Prepare to read again.
        if (!std::cin.eof()) {  // Haven't reached the end (this doesn't happen with keyboard input, but could happen with a file).
            std::cout << "\tIgnoring anything else you may have entered, starting over.\n";
            std::cin.clear();  // Set all stream state bits to zero, buffer NOT cleared.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer of everything.

            std::cout << "Enter a single integer: ";
            std::cin >> val;
        }
    }
    std::cout << "Invalid input, exiting." << std::endl;

    return 0;
}