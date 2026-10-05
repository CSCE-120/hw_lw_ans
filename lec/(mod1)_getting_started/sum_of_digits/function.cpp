#include "function.h"
#include <iostream>

int sum_of_digits(int value) {
    int sum = 0;

    // TODO(Student): Add the digits of value and store them in sum.
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    } return sum;
}