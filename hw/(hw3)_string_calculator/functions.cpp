#include <iostream>
#include <string>
#include "functions.h"

using std::string;

string add(const string& lhs, const string& rhs) {
    // TODO(student): compute sum of arguments
    std::string num1;
    std::string num2;
    std::string num_sum = "";
    
    bool neg_sum = false;
    if (((lhs.at(0) == '-') || (rhs.at(0) == '-')) && !((lhs.at(0) == '-') && (rhs.at(0) == '-'))) {
        if (lhs.at(0) == '-') {
            return subtract(rhs, lhs.substr(1));
        } if (rhs.at(0) == '-') {
            return subtract(lhs, rhs.substr(1));
        }
    } else if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
        neg_sum = true;
        if (lhs.substr(1).size() > rhs.substr(1).size()) {
            num1 = "0" + lhs.substr(1);
            num2 = std::string((lhs.substr(1).size() - rhs.substr(1).size() + 1), '0') + rhs.substr(1);
        } else if (lhs.substr(1).size() < rhs.substr(1).size()) {
            num1 = std::string((rhs.substr(1).size() - lhs.substr(1).size() + 1), '0') + lhs.substr(1);
            num2 = "0" + rhs.substr(1);
        } else {
            num1 = "0" + lhs.substr(1);
            num2 = "0" + rhs.substr(1);
        }
    } else {
        if (lhs.size() > rhs.size()) {
            num1 = "0" + lhs;
            num2 = std::string((lhs.size() - rhs.size() + 1), '0') + rhs;
        } else if (lhs.size() < rhs.size()) {
            num1 = std::string((rhs.size() - lhs.size() + 1), '0') + lhs;
            num2 = "0" + rhs;
        } else {
            num1 = "0" + lhs;
            num2 = "0" + rhs;
        }
    }

    int carry_digit = 0;
    for (int i = num1.size() - 1; i >= 0; i--) { 
        int digit_1 = num1.at(i) - '0'; 
        int digit_2 = num2.at(i) - '0'; 
        if ((carry_digit + digit_1 + digit_2) < 10) { 
            num_sum = std::to_string(carry_digit + digit_1 + digit_2) + num_sum; 
            carry_digit = 0;
        } else { 
            num_sum = std::to_string((carry_digit + digit_1 + digit_2) % 10) + num_sum; 
            carry_digit = 1; 
        } 
    }

    if (num_sum.find_first_of("123456789") == std::string::npos) {
        return "0";
    } if (neg_sum) {
        return ("-" + num_sum.substr(num_sum.find_first_of("123456789")));
    } return num_sum.substr(num_sum.find_first_of("123456789"));
}

string subtract(const string& lhs, const string& rhs) {
    // TODO(student): compute difference of arguments
    std::string num1;
    std::string num2;
    std::string num_diff = "";

    if (((lhs.at(0) == '-') || rhs.at(0) == '-') && !((lhs.at(0) == '-') && (rhs.at(0) == '-'))) {
        if (lhs.at(0) == '-') {
            return add(lhs, "-" + rhs);
        } if (rhs.at(0) == '-') {
            return add(lhs, rhs.substr(1));
        }
    } else if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
        return subtract(rhs.substr(1), lhs.substr(1));
    } else {
        if (lhs.size() > rhs.size()) {
            num1 = "0" + lhs;
            num2 = std::string((lhs.size() - rhs.size() + 1), '0') + rhs;
        } else if (lhs.size() < rhs.size()) {
            num1 = std::string((rhs.size() - lhs.size() + 1), '0') + lhs;
            num2 = "0" + rhs;
        } else {
            num1 = "0" + lhs;
            num2 = "0" + rhs;
        }
    }

    std::string greater_num = num1;
    std::string smaller_num = num2;
    bool neg_diff = false;
    for (unsigned int i = 0; i < greater_num.size(); i++) {
        if ((greater_num.at(i) - '0') > (smaller_num.at(i) - '0')) {
            break;
        } if ((greater_num.at(i) - '0') < (smaller_num.at(i) - '0')) {
            greater_num = num2;
            smaller_num = num1;
            neg_diff = true;
            break;
        }
    }

    int carry_digit = 0;
    bool borrow_digit = false;
    for (int i = (greater_num.size() - 1); i >= 0; i--) {
        int digit_1 = greater_num.at(i) - '0';
        int digit_2 = smaller_num.at(i) - '0';
        if (!(borrow_digit)) {
            if ((digit_1 - digit_2) < 0) {
                carry_digit = 10;
                borrow_digit = true;
                num_diff = std::to_string((carry_digit + digit_1) - digit_2) + num_diff;
            } else {
                carry_digit = 0;
                borrow_digit = false;
                num_diff = std::to_string((carry_digit + digit_1) - digit_2) + num_diff;
            } continue;
        } else {
            if (digit_1 == 0) {
                digit_1 = 9;
                borrow_digit = true;
                if ((digit_1 - digit_2) < 0) {
                    carry_digit = 10;
                    num_diff = std::to_string((carry_digit + digit_1) - digit_2) + num_diff;
                } else {
                    carry_digit = 0;
                    num_diff = std::to_string((carry_digit + digit_1) - digit_2) + num_diff;
                }
            } else {
                digit_1--;
                if ((digit_1 - digit_2) < 0) {
                    carry_digit = 10;
                    borrow_digit = true;
                    num_diff = std::to_string((carry_digit + digit_1) - digit_2) + num_diff;
                } else {
                    carry_digit = 0;
                    borrow_digit = false;
                    num_diff = std::to_string((carry_digit + digit_1) - digit_2) + num_diff;
                }
            } continue;
        }
    }

    if (num_diff.find_first_of("123456789") == std::string::npos) {
        return "0";
    } if (neg_diff) {
        return ("-" + num_diff.substr(num_diff.find_first_of("123456789")));
    } return num_diff.substr(num_diff.find_first_of("123456789"));
}

string multiply(const string& lhs, const string& rhs) {
    // TODO(student): compute product of arguments
    std::string num1;
    std::string num2;
    std::string num_prod = "0";

    if ((lhs.find_first_of("123456789") == std::string::npos) || (rhs.find_first_of("123456789") == std::string::npos)) {
        return "0";
    } if (((lhs.at(0) == '-') || (rhs.at(0) == '-')) && !((lhs.at(0) == '-') && (rhs.at(0) == '-'))) {
        if (lhs.at(0) == '-') {
            return "-" + multiply(lhs.substr(1), rhs);
        } if (rhs.at(0) == '-') {
            return "-" + multiply(lhs, rhs.substr(1));
        }
    } else if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
        return multiply(lhs.substr(1), rhs.substr(1));
    } else {
        num1 = lhs;
        num2 = rhs;
    }

    for (unsigned int i = 0; i < num2.size(); i++) {
        int place_product_1 = num2.at(i) - '0';
        for (unsigned int j = 0; j < num1.size(); j++) {
            int place_product_2 = num1.at(j) - '0';
            int pow_ten_zeros = (num1.size() - j - 1) + (num2.size() - i - 1);
            num_prod = add(num_prod, std::to_string(place_product_1 * place_product_2) + std::string(pow_ten_zeros, '0'));
        }
    } return num_prod;
}