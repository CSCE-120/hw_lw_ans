#include <iostream>
#include <string>

int main() {
    std::string word = "supercalifragilisticexpialidocious";
    std::cout << "The std::string is '" << word << "'" << std::endl;

    size_t index = 0;
    do {
        std::cout << "Enter index to show letter or 9999 to exit: ";
        if (std::cin >> index) {
            if (index != 9999) {
                try { // Attempt to run the code contained within the braces.
                    std::cout << word.at(index) << " is the letter at index " << index << std::endl;
                } catch (std::out_of_range& e) { // If out_of_range exception is encountered, run this:
                    std::cout << "out of range: " << e.what() << std::endl;
                } catch (...) { // For all other exceptions, run this:
                    std::cout << "unknown exception" << std::endl;
                }
            }
        } else {
            std::cout << "bad input, exiting" << std::endl;
            index = 9999;
        }
    } while (index != 9999);

    return 0;
}