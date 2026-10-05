#include <iostream>

int main() {
    // Variable declaration.
    double sum = 0;
    int counter = 0;

    // Reads and stores user input into variable value.
    std::cout << "Enter a series of integers. Last number is -1." << std::endl;
    int value = 0;
    std::cin >> value;
    if (std::cin.fail()) {
        std::cout << "ERROR, not a number, aborting" << std::endl;
        return -1;
    } // Terminate program with return -1 error indicator.

    // Loop until user input -1 to end.
    while (value != -1) {
        sum += value;
        counter++;

        std::cin >> value;
        if (std::cin.fail()) {
            std::cout << "ERROR, not a number, aborting" << std::endl;
            return -1;
        }
    }
    
    // Compute average. If no numbers inputted besides -1, there is no average to calculate.
    if (counter == 0) {
        std::cout << "No numbers were entered, there is no average." << std::endl;
    } else {
        std::cout << "The average is " << sum/counter << std::endl;
    }
}