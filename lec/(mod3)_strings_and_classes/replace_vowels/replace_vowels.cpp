#include <iostream>
#include <string>

// TODO(Student): Replace all vowels in the input string with "#".
// Hint: USEFUL STRING FUNCTIONS:
//                std::string.size() — Returns the number of characters in string.
//                std::string.find(txt) — Finds first instance of txt within string.
//                std::string.find_first_of(txt) — Finds first instance of any character within txt within string.
//                std::string.replace(index, len, txt) — String at index spanning len characters is replaced with txt.
//                std::string.at(index) — Returns character at index of string.
//                std::string.substr(begin, end) — Extracts portion of string from index begin to index end, excluding end.
//                std::string.substr(index) — Extracts portion of string starting from index onward to the rest of string.
std::string replace_vowels(std::string str) {
    while (str.find_first_of("aeiouAEIOU") != std::string::npos) {
        str.replace(str.find_first_of("aeiouAEIOU"), 1, "#");
    } return str;
}

// Prompt the user for input.
// Return a string containing the user's response.
std::string input(std::string prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int main() {
    std::string line = input("Enter a line of text:\n");
    std::string line_no_vowels = replace_vowels(line);
    std::cout << line_no_vowels << std::endl;
    return 0;
}