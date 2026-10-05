#include <iostream>
#include "functions.h"

// returns the boolean value true
// if and only if 1,000 <= a <= b < 1,000,000,000,000
bool is_valid_range(int64_t a, int64_t b) {
    // TODO(student)
    if ((1000 <= a) && (a <= b) && (b < 1000000000000)) {
        return true;
    } return false;
}

// returns 'p' if number is a plateau,
//         'b' if number is a basin,
//         'n' if number is neither
char classify_geo_type(int64_t number) {
    // TODO(student): Initialize local variables
    int digit_check_1;
    int digit_check_2;
    int digit_state = 0;

    bool is_plateau = false;
    bool is_basin = false;

    // TODO(student): Determine whether number is a plateau
    //                This is the key step
    for (int64_t i = number; i >= 10; i /= 10) {
        digit_check_1 = i % 10;
        digit_check_2 = (i / 10) % 10;

        if ((i == number) && (digit_check_2 <= digit_check_1)) {
            digit_state = -1;
            break;
        }

        if (digit_state == 0) {
            if (digit_check_2 > digit_check_1) {
                continue;
            } else if (digit_check_2 == digit_check_1) {
                digit_state++;
                continue;
            } else {
                digit_state = -1;
                break;
            }
        } else if (digit_state == 1) {
            if (digit_check_2 > digit_check_1) {
                digit_state = -1;
                break;
            } else if (digit_check_2 == digit_check_1) {
                continue;
            } else {
                digit_state++;
                continue;
            }
        } else if (digit_state == 2) {
            if (digit_check_2 > digit_check_1) {
                digit_state = -1;
                break;
            } else if (digit_check_2 == digit_check_1) {
                digit_state = -1;
                break;
            } else {
                continue;
            }
        }
        
    } if (digit_state == 2) {
        is_plateau = true;
    }

    // TODO(student): Determine whether number is a basin
    //                If you get the logic for plateau right,
    //                minor tweaks can create the code for basins.
    if (!(is_plateau)) {
        digit_state = 2;
        for (int64_t i = number; i >= 10; i /= 10) {
            digit_check_1 = i % 10;
            digit_check_2 = (i / 10) % 10;

            if ((i == number) && (digit_check_2 >= digit_check_1)) {
                digit_state = -1;
                break;
            }

            if (digit_state == 2) {
                if (digit_check_2 > digit_check_1) {
                    digit_state = -1;
                    break;
                } else if (digit_check_2 == digit_check_1) {
                    digit_state--;
                    continue;
                } else {
                    continue;
                }
            } else if (digit_state == 1) {
                if (digit_check_2 > digit_check_1) {
                    digit_state--;
                    continue;
                } else if (digit_check_2 == digit_check_1) {
                    continue;
                } else {
                    digit_state = -1;
                    break;
                }
            } else if (digit_state == 0) {
                if (digit_check_2 > digit_check_1) {
                    continue;
                } else if (digit_check_2 == digit_check_1) {
                    digit_state = -1;
                    break;
                } else {
                    digit_state = -1;
                    break;
                }
            }
            
        } if (digit_state == 0) {
            is_basin = true;
        }
    }

    // TODO(student): return the appropriate char:
    //                'p' for plateau,
    //                'b' for basin,
    //                'n' for neither
    if (is_plateau) {
        return 'p';
    } if (is_basin) {
        return 'b';
    } return 'n';
}

// returns how many numbers in the range [a, b] are plateaus and basins
plateaus_and_basins count_pb_numbers(int64_t a, int64_t b) {
    int number_of_plateaus = 0;
    int number_of_basins = 0;

    // TODO(student): count plateaus and basins in the range [a,b]
    for (int64_t i = a; i <= b; i++) {
        if (classify_geo_type(i) == 'p') {
            number_of_plateaus++;
        } else if (classify_geo_type(i) == 'b') {
            number_of_basins++;
        } else {
            continue;
        }
    }
    return {number_of_plateaus, number_of_basins};
}