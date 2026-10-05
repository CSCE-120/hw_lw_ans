#include <iostream>
#include <string>

// Define a struct
struct Student {
    std::string first_name = "";
    std::string last_name = "";
    int class_year = 0;
};

// Define function that prints student information; prevents hassle of printing individual variables for each struct.
void PrintStudent(Student student) {
    std::cout << student.first_name << " " << student.last_name << ", class of " << student.class_year;
}

int main() {
    // Define a struct variable.
    Student student;

    // Assign values to members of the struct.
    student.first_name = "Shawna";
    student.last_name = "Thomas";
    student.class_year = 2002;

    // Access members of the struct
    std::cout << "I am ";
    PrintStudent(student);
    std::cout << "." << std::endl;

    // Another way to declare a struct variable and set its members:
    Student grandfather;
    grandfather = {"Charles", "Miller", 1940};
    std::cout << "My grandfather was ";
    PrintStudent(grandfather);
    std::cout << "." << std::endl;
    
    // Another way, all on one line:
    Student ta({"Miss", "Rev", 2028});
    std::cout << "The TA is ";
    PrintStudent(ta);
    std::cout << "." << std::endl;
}