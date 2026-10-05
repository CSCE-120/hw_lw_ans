#include <iostream>
#include <limits>

int main() {
    // TODO(student): Determine the largest of three user–inputted integers. Print this value to console.
    // HINT(student): <limits> header file has std::numeric_limits<T> functions that can give max() and
    //                min() values possible to be handled by C++.

    std::cout << "Enter 3 numbers." << std::endl;
    int max_test = std::numeric_limits<int>::min();

    for (int i = 0; i < 3; i++) {
        int value = 0;
        std::cin >> value;
        std::cout << "Read in " << value << std::endl;

        if (std::cin.fail()) {
            std::cout << "ERROR. Invalid input, aborting." << std::endl;
            return -1;
        } if (value > max_test) {
            max_test = value;
        }
    } std::cout << "The greatest number of the three is: " << max_test << std::endl;
    
    return 0;
}