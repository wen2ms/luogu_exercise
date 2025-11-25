#include <algorithm>
#include <iostream>
#include <vector>

struct Person {
    std::string total;
    int id;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_of_people;
    std::cin >> num_of_people;
    std::vector<Person> persons(num_of_people);
    for (int i = 0; i < num_of_people; ++i) {
        std::cin >> persons[i].total;
        persons[i].id = i + 1;
    }
    std::sort(persons.begin(), persons.end(), [](const Person& first, const Person& second) {
        if (first.total.length() == second.total.length()) {
            return first.total > second.total;
        }
        return first.total.length() > second.total.length();
    });
    std::cout << persons[0].id << '\n';
    std::cout << persons[0].total << '\n';

    return 0;
}