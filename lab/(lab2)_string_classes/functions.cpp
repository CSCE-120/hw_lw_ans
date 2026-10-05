// add more includes as necessary
#include "functions.h"
#include <string>

// deobfuscate a sentence
// arg 1: obfuscated sentence
// arg 2: deobfuscation details
// returns the deobfuscated sentence
std::string deobfuscate(std::string sentence, std::string divide_words) {
    // TODO(student): give the function parameters descriptive names
    // TODO(student): implement the function
    std::string new_sent = "";
    if (sentence.size() == 0) {
        return new_sent;
    } for (int i = 0; i < divide_words.size(); i++) {
        int divide_digit = divide_words.at(i) - '0';
        if (divide_digit == 0 && i == 0) {
            continue;
        }
        new_sent += sentence.substr(0, divide_digit);
        sentence = sentence.substr(divide_digit);
        if (i != divide_words.size() - 1) {
            new_sent += " ";
        }
    } return new_sent;
}

// replace filter word with octothorpes (#)
// arg 1: sentence
// arg 2: filter word
// returns the filtered sentence
std::string wordFilter(std::string sentence, std::string filter) {
    // TODO(student): give the function parameters descriptive names
    // TODO(student): implement the function
    if (filter == "") {
        return sentence;
    } while (sentence.find(filter) != std::string::npos) {
        sentence.replace(sentence.find(filter), filter.size(), std::string(filter.size(), '#'));
    } return sentence;
}

// convert a string to a secure password
// arg 1: text
// returns a secure password based on the text
std::string passwordConverter(std::string password) {
    // TODO(student): give the function parameter a descriptive name
    // TODO(student): implement the function
    std::string new_pass = "";
    for (int i = 0; i < password.size(); i++) {
        switch (password.at(i)) {
            case 'a':
                new_pass += '@';
                break;
            case 'e':
                new_pass += '3';
                break;
            case 'i':
                new_pass += '!';
                break;
            case 'o':
                new_pass += '0';
                break;
            case 'u':
                new_pass += '^';
                break;
            default:
                new_pass += password.at(i);
                break;
        }
    }
    std::string new_pass_first_half = new_pass;
    for (int i = new_pass_first_half.size() - 1; i >= 0; i--) {
        new_pass += new_pass_first_half.at(i);
    } return new_pass;
}

// calculate the result of an arithmetic expression in words
// arg 1: expression using words
// returns an arithmetic equation using numerals and arithmetic symbols
std::string wordCalculator(std::string sentence) {
    // TODO(student): give the function parameter a descriptive name
    // TODO(student): implement the function
}

// count the palindromes in the text
// arg 1: text
// returns the number of palindromes in the text
unsigned int palindromeCounter(std::string) {
    // TODO(student): give the function parameter a descriptive name
    // TODO(student): implement the function
    return 0;
}
