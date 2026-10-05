#include <iostream>
#include <vector>

struct HiLoTemperature {
    double high = 0;
    double low = 0;
};

int main() {
    std::vector<HiLoTemperature> daily_temperatures;

    // Read in temperatures.
    std::cout << "Enter high and low temperatures for each day. " << "Enter a non-number to stop.\n";
    double high = 0;
    double low = 0;
    while (std::cin >> high >> low) {
        if (high < low) {
            std::cout << "Error, temperatures are out of order. " << "The high for the day comes first. Exiting.\n";
            return -1;
        } daily_temperatures.push_back({high, low});
    }

    // Print out temperatures.
    std::cout << "Daily high and low temperatures:\n";
    for (HiLoTemperature temperature : daily_temperatures) {
        std::cout << "\t(" << temperature.high << ", " << temperature.low << ")\n";
    }

    // Count number of days below freezing.
    unsigned int below_freezing = 0;
    for (HiLoTemperature temperature : daily_temperatures) {
        if (temperature.low < 32) {
        below_freezing++;
        }
    }
    std::cout << "Days below freezing: " << below_freezing << std::endl;

    // TODO(Student): Report hottest day.
    if (!(daily_temperatures.empty())) {
        unsigned int hot_day = 0;
        for (unsigned int i = 1; i < daily_temperatures.size(); i++) {
            if (daily_temperatures.at(i).high > daily_temperatures.at(hot_day).high) {
                hot_day = i;
            } std::cout << "Hottest day was day " << hot_day << " with high of " << daily_temperatures.at(hot_day).high << std::endl;
        }
    } else {
        std::cout << "No temperatures provided, cannot report hottest day." << std::endl;
    }

    // TODO(Student): If at least 3 daily temperatures, predict next day's temperatures as average of 
    //                last 3 days, otherwise error.
    if (daily_temperatures.size() >= 3) {
        HiLoTemperature prediction;
        for (unsigned int i = daily_temperatures.size() - 1; i > daily_temperatures.size() - 4; i--) {
            prediction.high += daily_temperatures.at(i).high;
            prediction.low += daily_temperatures.at(i).low;
        } std::cout << "Forecast: High of " << prediction.high / 3 << ", Low of " << prediction.low / 3 << std::endl;
    } else {
        std::cout << "Not enough days given to determine forecast." << std::endl;
    }

    return 0;
}