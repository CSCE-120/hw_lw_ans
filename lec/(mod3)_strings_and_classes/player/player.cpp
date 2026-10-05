#include <iostream>
#include <string>

class Player {
    std::string player_name;
    unsigned int jersey_number;
    std::string position;
    std::string fc_club;

    public:
    // Constructors: define what ways to build the object are allowed.
    Player() : player_name{""}, jersey_number{0}, position{""}, fc_club{""} {}
    Player(const std::string name, const unsigned int num, const std::string pos, const std::string club) : player_name{name}, jersey_number{num}, position{pos}, fc_club{club} {}

    // Getter Methods:
    std::string GetName() const {
        return player_name;
    } unsigned int GetJerseyNumber() const {
        return jersey_number;
    } std::string GetPosition() const {
        return position;
    } std::string GetClub() const {
        return fc_club;
    }

    // Setter Methods (only provide these if you trust the rest of the code):
    void SetName(const std::string s) {
        player_name = s;
    } void SetJerseyNumber(const unsigned int n) {
        jersey_number = n;
    } void SetPosition(const std::string s) {
        position = s;
    } void SetClub(const std::string c) {
        fc_club = c;
    }

    // Prints to cout, later we will learn how to generalize to any output method.
    void Print() const {
        std::cout << player_name << ", " << jersey_number << ", " << position << ", " << fc_club << std::endl;
    }
};

int main() {
    // Create player objects.
    Player turtle("Kylian Mbappé", 7, "FW", "Paris Saint-Germain");
    std::cout << turtle.GetName() << ", ";
    std::cout << turtle.GetJerseyNumber() << ", ";
    std::cout << turtle.GetPosition() << ", ";
    std::cout << turtle.GetClub() << std::endl;
    turtle.SetClub("Real Madrid");
    turtle.setJerseyNumber(10);
    turtle.Print();
}
