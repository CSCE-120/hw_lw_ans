#include <iostream>

// Define a struct.
struct Point {
    double x = 0;  // Initialize x–coordinate to 0.
    double y = 0;  // Initialize y–coordinate to 0.
};

int main() {
    // Define a struct variable that uses the structure of Point.
    Point p;

    // Assign values to members of the struct.
    p.x = 1.0;
    p.y = 2.5;

    // Access members of the struct.
    std::cout << "P: (" << p.x << ", " << p.y << ")" << std::endl;

    // Another way to declare a struct variable and set its members:
    Point q;
    q = {-4, 3.3};
    std::cout << "Q: (" << q.x << ", " << q.y << ")" << std::endl;

    // Another way, all on one line:
    Point r({10, -10});
    std::cout << "R: (" << r.x << ", " << r.y << ")" << std::endl;
}