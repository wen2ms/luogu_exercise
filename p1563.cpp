#include <iostream>
#include <string>
#include <vector>

int main() {
    int num_of_persons;
    int num_of_command;
    std::cin >> num_of_persons >> num_of_command;
    std::vector<std::pair<std::string, int>> persons(num_of_persons);
    for (auto& [name, direction] : persons) {
        std::cin >> direction >> name;
    }
    int pos = 0;
    for (int i = 0; i < num_of_command; ++i) {
        int direction;
        int count;
        std::cin >> direction >> count;
        if (persons[pos].second == direction) {
            pos = (pos + num_of_persons - count) % num_of_persons;
        } else {
            pos = (pos + count) % num_of_persons;
        }
    }
    std::cout << persons[pos].first << '\n';

    return 0;
}