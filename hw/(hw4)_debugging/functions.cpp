#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cstdint>
#include "functions.h"

int largest(int a, int b, int c) {
  int d = std::numeric_limits<int>::min();
  if (a > d) {
    d = a;
  } if (b > d) {
    d = b;
  } if (c > d) {
    d = c;
  } return d;
}

bool sum_is_even(int a, int b) {
  if((a + b) % 2 == 0){
    return true;
  } return false;
}

int boxes_needed(int apples) {
  if (apples <= 0) {
    return 0;
  } if (apples % 20 == 0) {
    return (apples / 20);
  } return (1 + (apples / 20));
}

bool smarter_section(int A_correct, int A_total, int B_correct, int B_total) {
  double A_right = A_correct;
  double A_all = A_total;
  double B_right = B_correct;
  double B_all = B_total;

  if ((A_right/A_all > 1) || (A_right/A_all < 0) || (B_right/B_all > 1) || (B_right/B_all < 0)) {
    throw std::invalid_argument("Invalid argument!");
  } return (A_right/A_all) > (B_right/B_all);
}

bool good_dinner(int pizzas, bool is_weekend) {
  if (((pizzas >= 10) && (pizzas <= 20)) && !(is_weekend)) {
    return true;
  } else if (is_weekend && (pizzas >= 10)) {
    return true;
  } return false;
}

int32_t sum_between(int32_t low, int32_t high) {
  if (low > high) {
    throw std::invalid_argument("Invalid argument!");
  } int64_t sum = (static_cast<int64_t>(high) - low + 1) * (static_cast<int64_t>(high) + low) / 2;
  if (sum > std::numeric_limits<int>::max() || sum < std::numeric_limits<int>::min()) {
    throw std::overflow_error("Overflow!");
  } return sum;
}

int64_t product(int64_t a, int64_t b) {
  if (a != 0 && b != 0) {
    if (a > 0 && b > 0 && a > std::numeric_limits<int64_t>::max() / b) {
      throw std::overflow_error("Overflow!");
    } if (a < 0 && b < 0 && a < std::numeric_limits<int64_t>::max() / b) {
      throw std::overflow_error("Overflow!");
    } if (a > 0 && b < 0 && b < std::numeric_limits<int64_t>::min() / a) {
      throw std::overflow_error("Overflow!");
    } if (a < 0 && b > 0 && a < std::numeric_limits<int64_t>::min() / b) {
      throw std::overflow_error("Overflow!");
    }
  } return a * b;
}