#include <iostream>
#include <string>
#include "rank_functions.h"

int main() {
    std::string file_name;
    std::cin >> file_name;
    std::ifstream in{file_name};

    // TODO(student): using load_driver_data(),
    //                create and load driver data into a vector of drivers
    std::vector<driver> racers = load_driver_data(in);

    // TODO(student): if loading driver data failed,
    //                1) print "Bad input" to standard output
    //                2) exit the program by returning 1
    if (!(in.is_open()) || racers.size() == 0) {
        std::cout << "Bad input" << std::endl;
        return 1;
    }

    // TODO(student): set the rankings of the drivers using set_rankings()
    racers = set_rankings(racers);

    // TODO(student): print the results using print_results()
    print_results(racers);

    return 0;
}
