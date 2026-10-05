#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "rank_functions.h"

// load data from the file stream into a vector
//   input format := <time> <country> <number> <name>
//   examples:
//     32.7 AUS 81 Piastri
//     36.5 NED 1  Verstappen
//   rank should be initialized to 0 for each driver
// returns a vector of drivers, or an empty vector if any input is invalid
std::vector<driver> load_driver_data(std::ifstream& file) {
    // TODO(student)
    std::vector<driver> drivers;
    std::string line;
    
    while(std::getline(file, line)) {
        line = trim(line);
        if (line == "") {
            return {};
        } std::istringstream iss(line); driver d{};

        if (!(iss >> d.time >> d.country >> d.number)) {
            return {};
        } std::getline(iss, d.lastname); d.lastname = trim(d.lastname);
        if (d.time <= 0) {
            return {};
        } if (d.country.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || d.country.size() != 3) {
            return {};
        } if (d.number < 1 || d.number > 99) {
            return {};
        } if (d.lastname.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ") != std::string::npos || d.lastname.size() < 2) {
            return {};
        }

        d.rank = 0;
        drivers.push_back(d);
    }

    return drivers;
}

// return a copy of the input vector with ranks set based on the time for each driver.
//   the fastest/minimum time is ranked 1
// the order of the elements in the vector should not be changed
std::vector<driver> set_rankings(std::vector<driver> drivers) {
    // TODO(student)
    for (unsigned int i = 0; i < drivers.size(); i++) {
        drivers.at(i).rank = 1;
        for (unsigned int j = 0; j < drivers.size(); j++) {
            if (drivers.at(j).time < drivers.at(i).time) {
                drivers.at(i).rank++;
            }
        }
    } return drivers;
}

// returns a copy of the input string with whitespace removed from the front and back
std::string trim(std::string s) {
    // TODO(student)
    if (s.find_first_not_of(" \t\r") == std::string::npos) {
        return "";
    } return s.substr(s.find_first_not_of(" \t\r"), s.find_last_not_of(" \t\r") - s.find_first_not_of(" \t\r") + 1);
}

// print the results of the race
void print_results(const std::vector<driver>& drivers) {
    // get the fastest time
    double best_time;
    for (const driver& driver : drivers) {
        if (driver.rank == 1) {
            best_time = driver.time;
            break;
        }
    }

    std::cout << "Final results!";
    std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
    for (unsigned rank = 1; rank <= drivers.size(); rank++) {
        for (const driver& driver : drivers) {
            if (driver.rank == rank) {
                std::string rank_str = "[" + std::to_string(rank) + "]";
                std::cout << std::setw(4) << std::left <<
                    rank_str << " " << driver.time << " " <<
                    std::setw(15) << std::left <<
                    driver.lastname << " (" << driver.country << ")" <<
                    " +" << (driver.time - best_time) << std::endl;
            }
        }
    }
}
