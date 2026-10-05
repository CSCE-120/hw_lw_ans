#include <iostream>
#include <string>

void check_height(int height, int minimum) {
    // TODO(Student): If height is negative, throw an std::invalid_argument with the message: "Heights can't be negative, you can't ride."
    //                If height is less than minimum, throw the string "Too short to ride!"
    if (height < 0) {
        throw std::invalid_argument("Heights can't be negative, you can't ride.");
    } if (height < minimum) {
        throw std::string("Too short to ride!");
    } std::cout << "Enjoy the ride!" << std::endl;
}

int main() {
    int height_required = 48;
    int height = 0;

    try {
        std::cout << "Enter your height in inches: ";
        // TODO(Student): Attempt to read in the height: if successful, call check_height, otherwise throw an std::invalid_argument with the message:
        //                "Invalid input, you can't ride". Catch any exceptions thrown. If someone is too short, also report the minimum height required.
        std::cin >> height;
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input, you can't ride.");
        } else {
            check_height(height, height_required);
        }
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    } catch (std::string& e) {
        std::cout << e << " You must be " << height_required << " inches tall." << std::endl;
    }

    std::cout << "Thank you for visiting!" << std::endl;
    return 0;
}