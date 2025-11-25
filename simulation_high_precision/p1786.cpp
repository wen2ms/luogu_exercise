#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct Person {
    std::string name;
    std::string job;
    int credit = 0;
    int level = 0;
    int input_order = 0;
};

int main() {
    int num_of_people;
    std::cin >> num_of_people;
    std::vector<Person> persons(num_of_people);
    for (int i = 0; i < num_of_people; ++i) {
        std::cin >> persons[i].name >> persons[i].job >> persons[i].credit >> persons[i].level;
        persons[i].input_order = i;
    }
    std::sort(persons.begin() + 3, persons.end(), [](const Person& person1, const Person& person2) {
        if (person1.credit == person2.credit) {
            return person1.input_order < person2.input_order;
        }
        return person1.credit > person2.credit;
    });
    for (int i = 3; i < num_of_people; ++i) {
        if (i == 3 || i == 4) {
            persons[i].job = "HuFa";
        } else if (i >= 5 && i <= 8) {
            persons[i].job = "ZhangLao";
        } else if (i >= 9 && i <= 15) {
            persons[i].job = "TangZhu";
        } else if (i >= 16 && i <= 40) {
            persons[i].job = "JingYing";
        } else if (i >= 41) {
            persons[i].job = "BangZhong";
        }
    }

    std::unordered_map<std::string, int> rank{{"BangZhu", 0}, {"FuBangZhu", 1}, {"HuFa", 2},     {"ZhangLao", 3},
                                              {"TangZhu", 4}, {"JingYing", 5},  {"BangZhong", 6}};

    std::sort(persons.begin(), persons.end(), [&](const Person& person1, const Person& person2) {
        if (rank[person1.job] == rank[person2.job]) {
            if (person1.level == person2.level) {
                return person1.input_order < person2.input_order;
            }
            return person1.level > person2.level;
        }
        return rank[person1.job] < rank[person2.job];
    });

    for (const Person& person : persons) {
        std::cout << person.name << ' ' << person.job << ' ' << person.level << '\n';
    }

    return 0;
}