#include <iostream>
#include <sstream>
#include <string>

double calculate(std::string line) {
    double first_number = 0;
    double second_number = 0;
    char op = ' ';

    std::istringstream iss(line);
    // TODO(Student): Extract <first_number> <op> <second_number> from iss any errors should throw an invalid_argument exception.
    if (!(iss >> first_number >> op >> second_number)) {
        throw std::invalid_argument("Unable to read input in " + line + "");
    }

    double result = 0;
    // TODO(Student): compute result based on op symbol, allowed symbols are +, -, *, / any errors should throw an invalid_argument exception.
    switch (op) {
        case '+':
            result = first_number + second_number;
            break;
        case '-':
            result = first_number - second_number;
            break;
        case '*':
            result = first_number * second_number;
            break;
        case '/':
            if (second_number == 0) {
                throw std::invalid_argument("Cannot divide by zero.");
            } result = first_number / second_number;
            break;
        default:
            std::ostringstream oss;
            oss << "Cannot support " << op << ", only (+), (-), (*), (/).";
            throw std::invalid_argument(oss.str());
            break;
    } return result;
}

int main() {
    std::cout << "Enter the expression to calculate in one line: " << std::endl;
    std::string line;
    std::getline(std::cin, line);

    try {
        std::cout << "result: " << calculate(line) << std::endl;
    } catch (const std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
    } return 0;
}