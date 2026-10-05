#include <iostream>
#include <vector>
#include <string>

// Create template variable for the print_vector function.
// This allows the function to accept vectors containing elements of any variable type (int, std::string, etc.)
template <typename T>
void print_vector(const std::vector<T>& v) {
    std::cout << '[';
    bool first = true;
    for (T element : v) {
        if (!(first)) {
            std::cout << ", ";
        } std::cout << element;
        first = false;
    } std::cout << ']';
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<std::string> v2 = {"gig", "'em", "aggies"};

    print_vector(v1);
    std::cout << std::endl;

    print_vector(v2);
    std::cout << std::endl;

    // std::cout cannot print vectors directly without operator overloading.
    // std::cout << v1 << std::endl << v2 << std::endl;
}