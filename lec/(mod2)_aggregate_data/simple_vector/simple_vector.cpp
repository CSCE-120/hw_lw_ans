#include <iostream>
#include <string>
#include <vector>

void PrintVector(std::string label, const std::vector<int> v) {
    std::cout << "The " << label << " vector elements:" << std::endl;
    for (unsigned int i = 0; i < v.size(); ++i) {
        std::cout << label << "[" << i << "] = " << v.at(i) << std::endl;
    } std::cout << std::endl;
}

// TODO(Student): Write a function SumVector that returns the sum of all the elements
int SumVector(const std::vector<int> v) {
    int sum = 0;
    for (unsigned int i = 0; i < v.size(); i++) {
        sum += v.at(i);
    } return sum;
}

// Hint: USEFUL VECTOR FUNCTIONS:
//       std::vector<T>.push_back(value) — Appends value to vector.
//       std::vector<T>.pop_back() — Removes last element of vector.
//       std::vector<T>.at(index) — Accesses the ith element of vector. Indexes start from 0.
//       std::vector<T>.size() — Returns the integer number of elements in vector.
//       std::vector<T>.empty() — Returns boolean of whether vector has elements or is empty.
//       std::vector<T>.insert(index, value) — Inserts value at index of vector.
//       std::vector<T>.erase(std::vector<T>.begin() + index) — Removes value at index of vector.

int main() {
    // Create an empty vector.
    std::vector<int> empty_vector;
    PrintVector("empty", empty_vector);

    // Initialize a vector with braces.
    std::vector<int> odds = {1, 3, 5, 7, 9};
    PrintVector("odds", odds);

    // Initialize a vector with 5 elements set to 0.
    std::vector<int> evens(5, 0);

    // Update all values
    for (unsigned int i = 0; i < evens.size(); ++i) {
        evens.at(i) = i * 2;
    }

    // Traverse and print values.
    PrintVector("evens", evens);

    // Access a single element
    std::cout << "front: " << evens.front() << std::endl;
    std::cout << "back: " << evens.back() << std::endl;
    std::cout << "at index 1: " << evens.at(1) << std::endl;

    // C++ does NOT support negative indexing! The following line results in an error!
    // std::cout << "at index -1: " << evens.at(-1) << std::endl;

    // Append contents to the vector.
    evens.push_back(10);
    evens.push_back(12);
    PrintVector("updated evens", evens);

    // Sum the values.
    // TODO(Student): Uncomment code once SumVector is written.
    std::cout << "The sum of the evens vector is " << SumVector(evens) << "." << std::endl;
}