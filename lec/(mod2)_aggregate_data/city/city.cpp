#include <iostream>
#include <string>

struct Coordinates {
    double latitude = 0;
    double longitude = 0;
};


// Define a nested struct
struct City {
    std::string name = "";
    std::string state = "";
    Coordinates gps_coordinates;
};


// Define function that prints city coordinates; prevents hassle of printing individual variables for each struct.
void PrintCity(City city) {
    std::cout << city.name << ", " << city.state << " located at [" << city.gps_coordinates.latitude << ", " << city.gps_coordinates.longitude << "]";
}

int main() {
    // Declare a nested struct variable.
    Coordinates coords({30.2672, -97.7431});
    City capital({"Austin", "TX", coords});

    std::cout << "The state capital is in ";
    PrintCity(capital);
    std::cout << "." << std::endl;

    // Declare a nested struct variable all on one line.
    City aggieland({"College Station", "TX", {30.601389, -96.314444}});

    std::cout << "The best university is in ";
    PrintCity(aggieland);
    std::cout << ", WHOOP!" << std::endl;
}